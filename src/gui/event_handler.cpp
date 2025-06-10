#include "gui/event_handler.hpp"

namespace gui
{
    EventHandler::EventHandler(engine::Board &b, gui::Window &w)
        : board(b), window(w), pieceSelected(false)
    {
    }

    void EventHandler::processEvents()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    handleClick(event.mouseButton.x, event.mouseButton.y);
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
    }

    void EventHandler::handleClick(int x, int y)
    {
        int row = y / squareSize;
        int col = x / squareSize;
        if (row < 0 || row > 7 || col < 0 || col > 7)
        {
            if (pieceSelected)
            {
                pieceSelected = false;
                board.getFigure(selectedRow, selectedCol).setSelected(false);
            }
            return;
        }
        if (!pieceSelected)
        {
            if (board.getFigure(row, col).getColor() == board.getCurrentTurn())
            {
                board.getFigure(row, col).setSelected(true);
                selectedRow = row;
                selectedCol = col;
                pieceSelected = true;
            }
        }
        else
        {
            board.getFigure(selectedRow, selectedCol).setSelected(false);
            pieceSelected = false;
            if (board.validMove(selectedRow, selectedCol, row, col))
            {
                board.update(selectedRow, selectedCol, row, col);
            }
        }
    }
}