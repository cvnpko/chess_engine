#include "engine/figure.hpp"

#define fi first
#define se second
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
    }/*
    bool Figure::validMove(int xStart, int yStart, int xEnd, int yEnd)
    {
        return true;
    }
*/
    void Figure::printValidMoves()
    {
        int n = validMoves.size();
        std::cout << getFigureValue() <<'\n';
        for(int i = 0; i < n; i++)
        {
            std::cout << "[" << validMoves[i].fi << " " << validMoves[i].se << "]\t";
        }
        std::cout << '\n';
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
            default:
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

    bool Figure::validMove(std::pair<int, int> newMove)
    {
        int n = validMoves.size();
        std::cout << n;
        for(int i = 0; i < n; i++)
        {
            std::cout << validMoves[i].fi << " " << validMoves[i].se << " " << newMove.fi << " " << newMove.se << '\n';
            if(validMoves[i].fi == newMove.fi && validMoves[i].se == newMove.se)
                return true;
            
        }
        return false;
    }

}