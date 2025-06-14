#ifndef CONFIG_SETTINGS_HPP
#define CONFIG_SETTINGS_HPP
#include <string>
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

    private:
        float squareSize;
        unsigned int curWidth, curHeight;
        std::string title;
    };
}

#endif