#include "engine/board.hpp"

namespace engine
{
    board::board()
    {
        board_grid[0][0] = figure(figure_type::ROOK, figure_color::BLACK);
        board_grid[0][7] = figure(figure_type::ROOK, figure_color::BLACK);
        board_grid[7][0] = figure(figure_type::ROOK, figure_color::WHITE);
        board_grid[7][7] = figure(figure_type::ROOK, figure_color::WHITE);
        board_grid[0][1] = figure(figure_type::KNIGHT, figure_color::BLACK);
        board_grid[0][6] = figure(figure_type::KNIGHT, figure_color::BLACK);
        board_grid[7][1] = figure(figure_type::KNIGHT, figure_color::WHITE);
        board_grid[7][6] = figure(figure_type::KNIGHT, figure_color::WHITE);
        board_grid[0][2] = figure(figure_type::BISHOP, figure_color::BLACK);
        board_grid[0][5] = figure(figure_type::BISHOP, figure_color::BLACK);
        board_grid[7][2] = figure(figure_type::BISHOP, figure_color::WHITE);
        board_grid[7][5] = figure(figure_type::BISHOP, figure_color::WHITE);
        board_grid[0][4] = figure(figure_type::KING, figure_color::BLACK);
        board_grid[0][3] = figure(figure_type::QUEEN, figure_color::BLACK);
        board_grid[7][4] = figure(figure_type::KING, figure_color::WHITE);
        board_grid[7][3] = figure(figure_type::QUEEN, figure_color::BLACK);
        for (int i = 0; i < 8; i++)
        {
            board_grid[1][i] = figure(figure_type::PAWN, figure_color::WHITE);
            board_grid[6][i] = figure(figure_type::PAWN, figure_color::BLACK);
        }
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board_grid[i][j] = figure();
            }
        }
    }
}