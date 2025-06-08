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
        int col = x / squareSize;
        int row = y / squareSize;
        if (row < 0 || row >= 8 || col < 0 || col >= 8)
        {
            return;
        }
        const engine::Figure &clickedFigure = board.getBoardGrid()[row][col];
        if (!pieceSelected)
        {
            if (clickedFigure.getType() != engine::FigureType::NONE)
            {
                selectedRow = row;
                selectedCol = col;
                pieceSelected = true;
            }
        }
        else
        {
            if (board.validMove(selectedRow, selectedCol, row, col))
            {
                board.update(selectedRow, selectedCol, row, col);
            }
            pieceSelected = false;
        }
    }
}