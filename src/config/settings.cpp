#include "config/settings.hpp"

namespace conf
{
    Settings::Settings() : title("Chess Engine"), squareSize(100.0f),
                           curWidth(800), curHeight(800),
                           minWidth(600), minHeight(600)
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
    int Settings::getMinimumHeight() const
    {
        return minHeight;
    }
    int Settings::getMinimumWidth() const
    {
        return minWidth;
    }
}