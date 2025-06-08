#include "engine/figure.hpp"

namespace engine
{
    Figure::Figure() : type(FigureType::NONE), color(FigureColor::NONE), pinned(false)
    {
    }
    Figure::Figure(FigureType type, FigureColor color)
    {
        this->type = type;
        this->color = color;
        pinned = false;
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
        return pinned;
    }
    void Figure::setPinned(bool pinstatus)
    {
        pinned = pinstatus;
    }
}