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
        void setBoardSide(BoardSide newSide);
        void changeBoardSide() const;
        const Figure (&getBoardGrid() const)[8][8];

    private:
        Figure boardGrid[8][8];
        BoardSide boardSide;
    };
}

#endif