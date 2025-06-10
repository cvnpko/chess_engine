#include "engine/figure.hpp"

namespace engine
{
    Figure::Figure()
        : type(FigureType::NONE), color(FigureColor::NONE), isPinned(false),
          isSelected(false)
    {
    }
    Figure::Figure(FigureType type, FigureColor color)
        : type(type), color(color), isPinned(false), isSelected(false)
    {
    }
    FigureType Figure::getType() const
    {
        return type;
    }
    FigureColor Figure::getColor() const
    {
        return color;
    }
    bool Figure::getPinned() const
    {
        return isPinned;
    }
    void Figure::setPinned(bool pinStatus)
    {
        isPinned = pinStatus;
    }
    bool Figure::getSelected() const
    {
        return isSelected;
    }
    void Figure::setSelected(bool selectStatus)
    {
        isSelected = selectStatus;
    }
    bool Figure::validMove(int xStart, int yStart, int xEnd, int yEnd)
    {
        return true;
    }
}