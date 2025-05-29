#include "engine/figure.hpp"

namespace engine
{
    figure::figure() : type(figure_type::NONE), color(figure_color::NONE) 
    {
        pinned = false;
    }
    figure::figure(figure_type type, figure_color color)
    {
        this->type = type;
        this->color = color;
        pinned = false;
    }

    figure_type figure::get_type() const
    {
        return type;
    }
    figure_color figure::get_color() const
    {
        return color;
    }

    bool figure::get_pinned() const
    {
        return pinned;
    }
    void figure::set_pinned(bool pinstatus)
    {
        pinned = pinstatus;
    }

}