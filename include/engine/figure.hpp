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
        bool getSelected() const;
        void setPinned(bool pinStatus);
        void setSelected(bool selectStatus);
        bool validMove(int xStart, int yStart, int xEnd, int yEnd);

    private:
        FigureType type;
        FigureColor color;
        bool isSelected;
        bool isPinned;
    };
}

#endif