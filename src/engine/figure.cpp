#include "engine/figure.hpp"

namespace engine
{
    Figure::Figure()
        : type(FigureType::NONE), color(FigureColor::NONE),
          isSelected(false)
    {
    }
    Figure::Figure(FigureType type, FigureColor color)
        : type(type), color(color), isSelected(false)
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

    int Figure::getFigureValue()
    {
        switch (type)
        {
            case FigureType::KING:
            {
                return 50; //subject to change just some random value
            }
            case FigureType::QUEEN:
            {
                return 8;
            }
            case FigureType::ROOK:
            {
                return 5;
            }
            case FigureType::BISHOP:
            {
                return 3;
            }
            case FigureType::KNIGHT:
            {
                return 3;
            }
            case FigureType::PAWN:
            {
                return 1;
            }
            case FigureType::NONE:
            {
                return 0;
            }
        }
    }

    void Figure::pushValidMove(std::pair<int ,int> newMove)
    {
        validMoves.push_back(newMove);
    }

    void Figure::resetValidMoves()
    {
        validMoves.clear();
    }

    bool Figure::getMoved()
    {
        return moved;
    }

    void Figure::setMoved()
    {
        moved = true;;
    }

}