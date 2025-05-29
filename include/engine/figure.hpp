#ifndef ENGINE_FIGURE_HPP
#define ENGINE_FIGURE_HPP

namespace engine
{
    enum class figure_color
    {
        WHITE,
        BLACK,
        NONE
    };
    enum class figure_type
    {
        KING,
        QUEEN,
        ROOK,
        KNIGHT,
        BISHOP,
        PAWN,
        NONE
    };
    class figure
    {
    public:
        figure();
        figure(figure_type type, figure_color color);
        figure_type get_type() const;
        figure_color get_color() const;

    private:
        figure_type type;
        figure_color color;
    };
}

#endif