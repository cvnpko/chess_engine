#ifndef ENGINE_TABLE_HPP
#define ENGINE_TABLE_HPP

#include "engine/figure.hpp"
#include <vector>

namespace engine
{
    enum class BoardSide
    {
        WHITE,
        BLACK
    };
    class Board
    {
    public:
        Board();
        BoardSide getBoardSide() const;
        Figure &getFigure(int x, int y);
        void setBoardSide(BoardSide newSide);
        void changeBoardSide();
        bool validMove(int xStart, int yStart, int xEnd, int yEnd);
        std::vector<std::pair<int, int>> possibleMoves(int xStart, int yStart);
        bool getIsSelected() const;
        int getSelectedRow() const;
        int getSelectedCol() const;
        bool isAttacked(int x, int y, FigureColor attackingColor, bool attackerUpwards);
        void deselect();
        void select(const int x, const int y);
        FigureColor getCurrentTurn() const;

    private:
        Figure boardGrid[8][8];
        BoardSide boardSide;
        FigureColor currentTurn;
        int selectedRow, selectedCol;
        int enPassantRow, enPassantCol;
        int whiteKingRow, whiteKingCol;
        int blackKingRow, blackKingCol;
        bool isSelected;
    };
}

#endif