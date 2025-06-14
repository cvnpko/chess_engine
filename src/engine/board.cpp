#include "engine/board.hpp"

namespace engine
{
    Board::Board() : isSelected(false), boardSide(BoardSide::WHITE),
                     currentTurn(FigureColor::WHITE)
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
            boardSide = newSide;
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
    }
    Figure &Board::getFigure(int x, int y)
    {
        return boardGrid[x][y];
    }
    bool Board::validMove(int xStart, int yStart, int xEnd, int yEnd)
    {
        return boardGrid[xStart][yStart].validMove(xStart, yStart, xEnd, yEnd);
    }
    void Board::update(int xStart, int yStart, int xEnd, int yEnd)
    {
        boardGrid[xEnd][yEnd] = boardGrid[xStart][yStart];
        boardGrid[xStart][yStart] = Figure();
        currentTurn = currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
    }
}