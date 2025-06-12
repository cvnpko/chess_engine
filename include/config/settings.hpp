#ifndef CONFIG_SETTINGS_HPP
#define CONFIG_SETTINGS_HPP

namespace conf
{
    class Settings
    {
    public:
        Settings();
        float getSquareSize() const;
        int getCurrentHeight() const;
        int getCurrentWidth() const;
        int getMinimumHeight() const;
        int getMinimumWidth() const;

    private:
        float squareSize;
        int curWidth, curHeight, minWidth, minHeight;
    };
}

#endif