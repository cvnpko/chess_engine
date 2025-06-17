#ifndef CONFIG_SETTINGS_HPP
#define CONFIG_SETTINGS_HPP
#include <string>
#include <SFML/Graphics.hpp>

namespace conf
{
    class Settings
    {
    public:
        Settings();
        std::string getTitle() const;
        float getSquareSize() const;
        int getCurrentHeight() const;
        int getCurrentWidth() const;
        sf::Color getBackgroundColor() const;

    private:
        float squareSize;
        sf::Color backgroundColor;
        unsigned int curWidth, curHeight;
        std::string title;
    };
}

#endif