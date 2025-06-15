#ifndef ENGINE_TABLE_HPP
#define ENGINE_TABLE_HPP

#include "engine/figure.hpp"
#include "engine/attack_field.hpp"
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

        std::pair<int, int> getEp(); 
        FigureColor getEpColor();
        void setEp(std::pair<int, int> newEp, FigureColor figure);
        void updateAttackBoard();
        int getControl(FigureColor color); 


    private:
        Figure boardGrid[8][8];
        BoardSide boardSide;
        FigureColor currentTurn;
        int selectedRow, selectedCol;
        bool isSelected;

        std::pair<int, int> ep;
        FigureColor epcolor;

        AttackField attackBoard[8][8];
        int whiteFieldControl;
        int blackFieldControl;
        
        std::pair<int, int> whiteKingPos;
        std::pair<int, int> blackKingPos;  

        void createAttackBoard();
    };
}

#endif