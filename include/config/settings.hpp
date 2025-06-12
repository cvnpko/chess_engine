#ifndef CONFIG_SETTINGS_HPP
#define CONFIG_SETTINGS_HPP
#include <string>
namespace conf
{
    class Settings
    {
    public:
        Settings();
        float getSquareSize() const;
        std::string getTitle() const;
        int getCurrentHeight() const;
        int getCurrentWidth() const;
        int getMinimumHeight() const;
        int getMinimumWidth() const;

    private:
        float squareSize;
        unsigned int curWidth, curHeight, minWidth, minHeight;
        std::string title;
    };
}

#endif