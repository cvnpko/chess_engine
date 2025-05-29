#ifndef ENGINE_TABLE_HPP
#define ENGINE_TABLE_HPP

#include "engine/figure.hpp"

namespace engine
{
    class board
    {
    public:
        board();

    private:
        figure board_grid[8][8];
    };
}

#endif