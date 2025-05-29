#include "engine/figure.hpp"

namespace engine
{
    Figure::Figure() : type(Figure_type::NONE), color(Figure_color::NONE) 
    {
        pinned = false;
    }
    Figure::Figure(Figure_type type, Figure_color color)
    {
        this->type = type;
        this->color = color;
        pinned = false;
    }

    Figure_type Figure::get_type() const
    {
        return type;
    }
    Figure_color Figure::get_color() const
    {
        return color;
    }

    bool Figure::get_pinned() const
    {
        return pinned;
    }
    void Figure::set_pinned(bool pinstatus)
    {
        pinned = pinstatus;
    }

}