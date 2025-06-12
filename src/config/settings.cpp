#include "config/settings.hpp"

namespace conf
{
    Settings::Settings() : title("Chess Engine"), squareSize(100.0f),
                           curWidth(800), curHeight(800)
    {
    }
    std::string Settings::getTitle() const
    {
        return title;
    }
    float Settings::getSquareSize() const
    {
        return squareSize;
    }
    int Settings::getCurrentHeight() const
    {
        return curHeight;
    }
    int Settings::getCurrentWidth() const
    {
        return curWidth;
    }
}