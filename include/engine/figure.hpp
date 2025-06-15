#ifndef ENGINE_FIGURE_HPP
#define ENGINE_FIGURE_HPP

#include <vector>
#include <utility>

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
        bool getSelected() const;
        void setSelected(bool selectStatus);
        bool validMove(int xStart, int yStart, int xEnd, int yEnd);

        void pushValidMove(std::pair<int, int> newMove);
        void resetValidMoves();
        void setMoved();
        bool getMoved();
        
        int getFigureValue();
    private:
        std::vector<std::pair<int, int>> validMoves;
        FigureType type;
        FigureColor color;
        bool isSelected;
        bool moved;
    };
}

#endif