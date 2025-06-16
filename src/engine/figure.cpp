#include "engine/figure.hpp"

namespace engine
{
    Figure::Figure()
        : type(FigureType::NONE), color(FigureColor::NONE), movedBefore(false),
          isSelected(false)
    {
    }
    Figure::Figure(FigureType type, FigureColor color)
        : type(type), color(color), movedBefore(false), isSelected(false)
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
    bool Figure::getMovedBefore() const
    {
        return movedBefore;
    }
    void Figure::setMovedBefore(bool val)
    {
        movedBefore = val;
    }
    bool Figure::getSelected() const
    {
        return isSelected;
    }
    void Figure::setSelected(bool selectStatus)
    {
        isSelected = selectStatus;
    }
    bool Figure::validMove(int xStart, int yStart, int xEnd, int yEnd, bool directionUpwards) const
    {
        if (xStart == xEnd && yStart == yEnd)
        {
            return false;
        }
        switch (type)
        {
        case FigureType::ROOK:
            return xStart == xEnd || yStart == yEnd;
            break;
        case FigureType::BISHOP:
            return xStart + yStart == xEnd + yEnd ||
                   xStart - yStart == xEnd - yEnd;
            break;
        case FigureType::KNIGHT:
            return ((xStart - xEnd == 1 || xStart - xEnd == -1) && (yStart - yEnd == 2 || yStart - yEnd == -2)) ||
                   ((xStart - xEnd == 2 || xStart - xEnd == -2) && (yStart - yEnd == 1 || yStart - yEnd == -1));
            break;
        case FigureType::KING:
            if (xStart - xEnd >= -1 && xStart - xEnd <= 1 && yStart - yEnd >= -1 && yStart - yEnd <= 1)
            {
                return true;
            }
            if (!movedBefore && xStart == xEnd && (yStart - yEnd == 2 || yStart - yEnd == -2))
            {
                return true;
            }
            return false;

            break;
        case FigureType::QUEEN:
            return xStart == xEnd || yStart == yEnd ||
                   xStart + yStart == xEnd + yEnd ||
                   xStart - yStart == xEnd - yEnd;
            break;
        case FigureType::PAWN:
            if (yStart == yEnd)
            {
                if ((directionUpwards && xStart - 1 == xEnd) || (!directionUpwards && xStart + 1 == xEnd))
                {
                    return true;
                }
                if (!movedBefore && ((directionUpwards && xStart - 2 == xEnd) || (!directionUpwards && xStart + 2 == xEnd)))
                {
                    return true;
                }
                return false;
            }
            if (yStart + 1 == yEnd || yStart - 1 == yEnd)
            {
                if ((directionUpwards && xStart - 1 == xEnd) || (!directionUpwards && xStart + 1 == xEnd))
                {
                    return true;
                }
                return false;
            }
            return false;
            break;
        case FigureType::NONE:
        default:
            return false;
        }
    }
    std::vector<std::pair<int, int>> Figure::possibleMoves(int xStart, int yStart, bool directionUpwards)
    {
        std::vector<std::pair<int, int>> ret;
        switch (type)
        {
        case FigureType::ROOK:
            for (int i = 0; i < 8; i++)
            {
                if (i != yStart)
                {
                    ret.push_back({xStart, i});
                }
                if (i != xStart)
                {
                    ret.push_back({i, yStart});
                }
            }
            break;
        case FigureType::BISHOP:
            for (int i = xStart + 1, j = yStart + 1; i < 8 && j < 8; i++, j++)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart - 1, j = yStart - 1; i >= 0 && j >= 0; i--, j--)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart + 1, j = yStart - 1; i < 8 && j >= 0; i++, j--)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart - 1, j = yStart + 1; i >= 0 && j < 8; i--, j++)
            {
                ret.push_back({i, j});
            }
            break;
        case FigureType::KNIGHT:
        {
            int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
            int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
            for (int i = 0; i < 8; i++)
            {
                int tx = dx[i] + xStart;
                int ty = dy[i] + yStart;
                if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8)
                {
                    ret.push_back({tx, ty});
                }
            }
        }
        break;
        case FigureType::KING:
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int tx = xStart + i, ty = yStart + j;
                    if (i != 0 || j != 0 && tx >= 0 && tx < 8 && ty >= 0 && ty < 8)
                    {
                        ret.push_back({tx, ty});
                    }
                }
            }
            if (movedBefore)
            {
                ret.push_back({xStart, yStart - 2});
                ret.push_back({xStart, yStart + 2});
            }
            break;
        case FigureType::QUEEN:
            for (int i = xStart + 1, j = yStart + 1; i < 8 && j < 8; i++, j++)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart - 1, j = yStart - 1; i >= 0 && j >= 0; i--, j--)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart + 1, j = yStart - 1; i < 8 && j >= 0; i++, j--)
            {
                ret.push_back({i, j});
            }
            for (int i = xStart - 1, j = yStart + 1; i >= 0 && j < 8; i--, j++)
            {
                ret.push_back({i, j});
            }
            for (int i = 0; i < 8; i++)
            {
                if (i != yStart)
                {
                    ret.push_back({xStart, i});
                }
                if (i != xStart)
                {
                    ret.push_back({i, yStart});
                }
            }
            break;
        case FigureType::PAWN:
        {
            int dir = directionUpwards ? -1 : 1;

            ret.push_back({xStart + dir, yStart});
            if (yStart != 0)
            {
                ret.push_back({xStart + dir, yStart - 1});
            }
            if (yStart != 7)
            {
                ret.push_back({xStart + dir, yStart + 1});
            }
            if (movedBefore)
            {
                ret.push_back({xStart + 2 * dir, yStart});
            }
        }
        break;
        case FigureType::NONE:
            break;
        default:
            break;
        }
        return ret;
    }
}