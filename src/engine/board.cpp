#include "engine/board.hpp"

namespace engine
{
    Board::Board() : isSelected(false), enPassantRow(-1), enPassantCol(-1), boardSide(BoardSide::WHITE),
                     currentTurn(FigureColor::WHITE), whiteKingRow(7), whiteKingCol(4),
                     blackKingRow(0), blackKingCol(4)
    {
        boardGrid[0][0] = Figure(FigureType::ROOK, FigureColor::BLACK);
        boardGrid[0][7] = Figure(FigureType::ROOK, FigureColor::BLACK);
        boardGrid[7][0] = Figure(FigureType::ROOK, FigureColor::WHITE);
        boardGrid[7][7] = Figure(FigureType::ROOK, FigureColor::WHITE);
        boardGrid[0][1] = Figure(FigureType::KNIGHT, FigureColor::BLACK);
        boardGrid[0][6] = Figure(FigureType::KNIGHT, FigureColor::BLACK);
        boardGrid[7][1] = Figure(FigureType::KNIGHT, FigureColor::WHITE);
        boardGrid[7][6] = Figure(FigureType::KNIGHT, FigureColor::WHITE);
        boardGrid[0][2] = Figure(FigureType::BISHOP, FigureColor::BLACK);
        boardGrid[0][5] = Figure(FigureType::BISHOP, FigureColor::BLACK);
        boardGrid[7][2] = Figure(FigureType::BISHOP, FigureColor::WHITE);
        boardGrid[7][5] = Figure(FigureType::BISHOP, FigureColor::WHITE);
        boardGrid[0][4] = Figure(FigureType::KING, FigureColor::BLACK);
        boardGrid[0][3] = Figure(FigureType::QUEEN, FigureColor::BLACK);
        boardGrid[7][4] = Figure(FigureType::KING, FigureColor::WHITE);
        boardGrid[7][3] = Figure(FigureType::QUEEN, FigureColor::WHITE);
        for (int i = 0; i < 8; i++)
        {
            boardGrid[1][i] = Figure(FigureType::PAWN, FigureColor::BLACK);
            boardGrid[6][i] = Figure(FigureType::PAWN, FigureColor::WHITE);
        }
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                boardGrid[i][j] = Figure();
            }
        }
    }
    BoardSide Board::getBoardSide() const
    {
        return boardSide;
    }
    FigureColor Board::getCurrentTurn() const
    {
        return currentTurn;
    }
    bool Board::getIsSelected() const
    {
        return isSelected;
    }
    int Board::getSelectedRow() const
    {
        return selectedRow;
    }
    int Board::getSelectedCol() const
    {
        return selectedCol;
    }
    void Board::setBoardSide(BoardSide newSide)
    {
        if (newSide != boardSide)
        {
            Board::changeBoardSide();
        }
    }
    void Board::deselect()
    {
        if (isSelected)
        {
            isSelected = false;
            boardGrid[selectedRow][selectedCol].setSelected(false);
        }
    }
    void Board::select(int x, int y)
    {
        if (isSelected)
        {
            boardGrid[selectedRow][selectedCol].setSelected(false);
        }
        isSelected = true;
        boardGrid[x][y].setSelected(true);
        selectedRow = x;
        selectedCol = y;
    }
    void Board::changeBoardSide()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Figure tempFig = boardGrid[i][j];
                boardGrid[i][j] = boardGrid[7 - i][j];
                boardGrid[7 - i][j] = tempFig;
            }
        }
        std::swap(blackKingRow, whiteKingRow);
        std::swap(blackKingCol, whiteKingCol);
        boardSide = boardSide == BoardSide::BLACK ? BoardSide::WHITE : BoardSide::BLACK;
    }
    Figure &Board::getFigure(int x, int y)
    {
        return boardGrid[x][y];
    }
    bool Board::validMove(int xStart, int yStart, int xEnd, int yEnd)
    {
        if (xStart >= 8 || xStart < 0 || xEnd >= 8 || xEnd < 0 || yStart >= 8 || yStart < 0 || yEnd >= 8 || yEnd < 0)
        {
            return false;
        }
        const Figure &start = boardGrid[xStart][yStart];
        const Figure &end = boardGrid[xEnd][yEnd];
        bool directionUpwards = (boardSide == BoardSide::BLACK &&
                                 start.getColor() == FigureColor::BLACK) ||
                                (boardSide == BoardSide::WHITE &&
                                 start.getColor() == FigureColor::WHITE);
        if (!start.validMove(xStart, yStart, xEnd, yEnd, directionUpwards))
        {
            return false;
        }
        if (start.getColor() == end.getColor())
        {
            return false;
        }
        bool shouldCastle = false;
        bool shouldEnPassant = false;
        bool shouldPossibleEnPassant = false;
        int newKingCol, newKingRow;
        if (currentTurn == FigureColor::WHITE)
        {
            newKingCol = whiteKingCol;
            newKingRow = whiteKingRow;
        }
        else
        {
            newKingCol = blackKingCol;
            newKingRow = blackKingRow;
        }
        switch (start.getType())
        {
        case FigureType::ROOK:
        case FigureType::BISHOP:
        case FigureType::QUEEN:
        {
            int xDir = xStart == xEnd ? 0 : (xStart < xEnd ? 1 : -1);
            int yDir = yStart == yEnd ? 0 : (yStart < yEnd ? 1 : -1);
            int xTmp = xStart + xDir;
            int yTmp = yStart + yDir;
            while (xTmp != xEnd || yTmp != yEnd)
            {
                if (boardGrid[xTmp][yTmp].getType() != FigureType::NONE)
                {
                    return false;
                }
                xTmp += xDir;
                yTmp += yDir;
            }
        }
        break;
        case FigureType::KING:
            if (yStart - yEnd == 2 || yStart - yEnd == -2)
            {
                if (start.getMovedBefore())
                {
                    return false;
                }
                if (boardGrid[xStart][yStart < yEnd ? 7 : 0].getColor() != boardGrid[xStart][yStart].getColor() ||
                    boardGrid[xStart][yStart < yEnd ? 7 : 0].getType() != FigureType::ROOK ||
                    boardGrid[xStart][yStart < yEnd ? 7 : 0].getMovedBefore())
                {
                    return false;
                }
                int dir = yStart < yEnd ? 1 : -1;
                int tmp = yStart + dir;
                while (tmp > 0 && tmp < 7)
                {
                    if (boardGrid[xStart][tmp].getType() != FigureType::NONE)
                    {
                        return false;
                    }
                    tmp += dir;
                }
                if (isAttacked(xStart, yStart, currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE, !directionUpwards) ||
                    isAttacked(xStart, yStart + dir, currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE, !directionUpwards) ||
                    isAttacked(xStart, yStart + 2 * dir, currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE, !directionUpwards))
                {
                    return false;
                }
                shouldCastle = true;
            }
            else
            {
                newKingRow = xEnd;
                newKingCol = yEnd;
            }
            break;
        case FigureType::PAWN:
            if (yStart != yEnd)
            {
                if (end.getType() == FigureType::NONE)
                {
                    if (xStart != enPassantRow || yEnd != enPassantCol)
                    {
                        return false;
                    }
                    else
                    {
                        shouldEnPassant = true;
                    }
                }
            }
            else
            {
                if (end.getType() != FigureType::NONE)
                {
                    return false;
                }
                if (xStart - xEnd == 2 || xStart - xEnd == -2)
                {
                    if (boardGrid[(xStart + xEnd) / 2][yStart].getType() != FigureType::NONE)
                    {
                        return false;
                    }
                    shouldPossibleEnPassant = true;
                }
            }
            break;
        }
        Figure tmp1 = boardGrid[xEnd][yEnd], tmp2;
        boardGrid[xEnd][yEnd] = boardGrid[xStart][yStart];
        boardGrid[xStart][yStart] = Figure();
        if (!shouldCastle)
        {
            if (shouldEnPassant)
            {
                Figure tmp2 = boardGrid[xStart][yEnd];
                boardGrid[xStart][yEnd] = Figure();
            }
            if (currentTurn == FigureColor::BLACK && isAttacked(blackKingRow, blackKingCol, FigureColor::WHITE, boardSide == BoardSide::WHITE) ||
                currentTurn == FigureColor::WHITE && isAttacked(whiteKingRow, whiteKingCol, FigureColor::BLACK, boardSide == BoardSide::BLACK))
            {
                boardGrid[xStart][yStart] = boardGrid[xEnd][yEnd];
                boardGrid[xEnd][yEnd] = tmp1;
                if (shouldEnPassant)
                {
                    boardGrid[xStart][yEnd] = tmp2;
                }
                return false;
            }
            else
            {
                if (currentTurn == FigureColor::WHITE)
                {
                    whiteKingCol = newKingCol;
                    whiteKingRow = newKingRow;
                }
                else
                {
                    blackKingCol = newKingCol;
                    blackKingRow = newKingRow;
                }
                if (shouldPossibleEnPassant)
                {
                    enPassantRow = xEnd;
                    enPassantCol = yEnd;
                }
                else
                {
                    enPassantRow = enPassantCol = -1;
                }
                currentTurn = currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
                boardGrid[xEnd][yEnd].setMovedBefore(true);
                return true;
            }
        }
        else
        {
            enPassantRow = enPassantCol = -1;
            if (yStart < yEnd)
            {
                boardGrid[xStart][yEnd - 1] = boardGrid[xStart][7];
                boardGrid[xStart][7] = Figure();
                boardGrid[xStart][yEnd - 1].setMovedBefore(true);
            }
            else
            {
                boardGrid[xStart][yEnd + 1] = boardGrid[xStart][0];
                boardGrid[xStart][0] = Figure();
                boardGrid[xStart][yEnd + 1].setMovedBefore(true);
            }
            newKingRow = xEnd;
            newKingCol = yEnd;
            currentTurn = currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
            boardGrid[xEnd][yEnd].setMovedBefore(true);
            return true;
        }
    }
    bool Board::isAttacked(int x, int y, FigureColor attackingColor, bool attackerUpwards)
    {
        int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
        int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 &&
                boardGrid[tx][ty].getType() == FigureType::KNIGHT &&
                boardGrid[tx][ty].getColor() == attackingColor)
            {
                return true;
            }
        }
        if (attackerUpwards && x != 7)
        {
            if ((y != 0 && boardGrid[x + 1][y - 1].getType() == FigureType::PAWN &&
                 boardGrid[x + 1][y - 1].getColor() == attackingColor) ||
                (y != 7 && boardGrid[x + 1][y + 1].getType() == FigureType::PAWN &&
                 boardGrid[x + 1][y + 1].getColor() == attackingColor))
            {
                return true;
            }
        }
        if (!attackerUpwards && x != 0)
        {
            if ((y != 0 && boardGrid[x - 1][y - 1].getType() == FigureType::PAWN &&
                 boardGrid[x - 1][y - 1].getColor() == attackingColor) ||
                (y != 7 && boardGrid[x - 1][y + 1].getType() == FigureType::PAWN &&
                 boardGrid[x - 1][y + 1].getColor() == attackingColor))
            {
                return true;
            }
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int tx = x + i, ty = y + j;
                if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 &&
                    boardGrid[tx][ty].getType() == FigureType::KING &&
                    boardGrid[tx][ty].getColor() == attackingColor)
                {
                    return true;
                }
            }
        }
        for (int i = x + 1; i < 8; i++)
        {
            if (boardGrid[i][y].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][y].getType() == FigureType::ROOK ||
                     boardGrid[i][y].getType() == FigureType::QUEEN) &&
                    boardGrid[i][y].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = x - 1; i >= 0; i--)
        {
            if (boardGrid[i][y].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][y].getType() == FigureType::ROOK ||
                     boardGrid[i][y].getType() == FigureType::QUEEN) &&
                    boardGrid[i][y].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = y + 1; i < 8; i++)
        {
            if (boardGrid[x][i].getType() != FigureType::NONE)
            {
                if ((boardGrid[x][i].getType() == FigureType::ROOK ||
                     boardGrid[x][i].getType() == FigureType::QUEEN) &&
                    boardGrid[x][i].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--)
        {
            if (boardGrid[x][i].getType() != FigureType::NONE)
            {
                if ((boardGrid[x][i].getType() == FigureType::ROOK ||
                     boardGrid[x][i].getType() == FigureType::QUEEN) &&
                    boardGrid[x][i].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
        {
            if (boardGrid[i][j].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][j].getType() == FigureType::BISHOP ||
                     boardGrid[i][j].getType() == FigureType::QUEEN) &&
                    boardGrid[i][j].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
        {
            if (boardGrid[i][j].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][j].getType() == FigureType::BISHOP ||
                     boardGrid[i][j].getType() == FigureType::QUEEN) &&
                    boardGrid[i][j].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
        {
            if (boardGrid[i][j].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][j].getType() == FigureType::BISHOP ||
                     boardGrid[i][j].getType() == FigureType::QUEEN) &&
                    boardGrid[i][j].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (boardGrid[i][j].getType() != FigureType::NONE)
            {
                if ((boardGrid[i][j].getType() == FigureType::BISHOP ||
                     boardGrid[i][j].getType() == FigureType::QUEEN) &&
                    boardGrid[i][j].getColor() == attackingColor)
                {
                    return true;
                }
                break;
            }
        }
        return false;
    }
}