#include "engine/figure.hpp"

namespace engine
{
    figure::figure()
        : type(figure_type::NONE), color(figure_color::NONE) {}
    figure::figure(figure_type type, figure_color color)
        : type(type), color(color) {}

    figure_type figure::get_type() const
    {
        return type;
    }
    figure_color figure::get_color() const
    {
        return color;
    }
}