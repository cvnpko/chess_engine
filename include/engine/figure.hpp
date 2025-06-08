#ifndef ENGINE_FIGURE_HPP
#define ENGINE_FIGURE_HPP

namespace engine
{
    enum class FigureColor
    {
        WHITE,
        BLACK,
        NONE
    };
    enum class FigureType
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
        Figure(FigureType type, FigureColor color);
        FigureType getType() const;
        FigureColor getColor() const;
        bool getPinned() const;
        void setPinned(bool pinStatus);
        bool validMove(int x_start, int y_start, int x, int y);

    private:
        FigureType type;
        FigureColor color;
        bool pinned;
    };
}

#endif