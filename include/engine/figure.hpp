#ifndef ENGINE_FIGURE_HPP
#define ENGINE_FIGURE_HPP

namespace engine
{
    enum class Figure_color
    {
        WHITE,
        BLACK,
        NONE
    };
    enum class Figure_type
    {
        KING,
        QUEEN,
        ROOK,
        KNIGHT,
        BISHOP,
        PAWN,
        NONE
    };
    class Figure
    {
    public:
        Figure();
        Figure(Figure_type type, Figure_color color);
        Figure_type get_type() const;
        Figure_color get_color() const;
        bool get_pinned() const;
        void set_pinned(bool pin_status);
    private:
        Figure_type type;
        Figure_color color;
        bool pinned;
    };
}

#endif