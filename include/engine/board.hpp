#ifndef ENGINE_TABLE_HPP
#define ENGINE_TABLE_HPP

#include "engine/figure.hpp"

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
                void update(int xStart, int yStart, int xEnd, int yEnd);
                bool getIsSelected() const;
                int getSelectedRow() const;
                int getSelectedCol() const;
                void deselect();
                void select(const int x, const int y);
                FigureColor getCurrentTurn() const;

        private:
                Figure boardGrid[8][8];
                BoardSide boardSide;
                FigureColor currentTurn;
                int selectedRow, selectedCol;
                bool isSelected;
        };
}

#endif