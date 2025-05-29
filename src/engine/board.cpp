#include "engine/board.hpp"

namespace engine
{
    Board::Board()
    {
        board_side = BoardSide::WHITE;

        board_grid[0][0] = Figure(Figure_type::ROOK, Figure_color::BLACK);
        board_grid[0][7] = Figure(Figure_type::ROOK, Figure_color::BLACK);
        board_grid[7][0] = Figure(Figure_type::ROOK, Figure_color::WHITE);
        board_grid[7][7] = Figure(Figure_type::ROOK, Figure_color::WHITE);
        board_grid[0][1] = Figure(Figure_type::KNIGHT, Figure_color::BLACK);
        board_grid[0][6] = Figure(Figure_type::KNIGHT, Figure_color::BLACK);
        board_grid[7][1] = Figure(Figure_type::KNIGHT, Figure_color::WHITE);
        board_grid[7][6] = Figure(Figure_type::KNIGHT, Figure_color::WHITE);
        board_grid[0][2] = Figure(Figure_type::BISHOP, Figure_color::BLACK);
        board_grid[0][5] = Figure(Figure_type::BISHOP, Figure_color::BLACK);
        board_grid[7][2] = Figure(Figure_type::BISHOP, Figure_color::WHITE);
        board_grid[7][5] = Figure(Figure_type::BISHOP, Figure_color::WHITE);
        board_grid[0][4] = Figure(Figure_type::KING, Figure_color::BLACK);
        board_grid[0][3] = Figure(Figure_type::QUEEN, Figure_color::BLACK);
        board_grid[7][4] = Figure(Figure_type::KING, Figure_color::WHITE);
        board_grid[7][3] = Figure(Figure_type::QUEEN, Figure_color::BLACK);
        for (int i = 0; i < 8; i++)
        {
            board_grid[1][i] = Figure(Figure_type::PAWN, Figure_color::BLACK);
            board_grid[6][i] = Figure(Figure_type::PAWN, Figure_color::WHITE);
        }
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board_grid[i][j] = Figure();
            }
        }
    }

    BoardSide Board::get_board_side() const
    {
        return board_side;
    }

    void Board::set_board_side(BoardSide new_side)
    {
        if(new_side != board_side)
        {
            Board::change_board_side();
            board_side = new_side;
        }
    }

    void Board::change_board_side() const
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                Figure temp_fig = board_grid[i][j];
                (Figure)board_grid[i][j] = board_grid[7 - i][j];
                (Figure)board_grid[7 - i][j] = temp_fig;
            }
        }
    }
}