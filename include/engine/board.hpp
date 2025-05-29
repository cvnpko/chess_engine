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
        BoardSide get_board_side() const;
        void set_board_side(BoardSide new_side);
        void change_board_side() const;
    private:
        Figure board_grid[8][8];
        BoardSide board_side;
       


    };
}

#endif