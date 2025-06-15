#include "gui/event_handler.hpp"

namespace gui
{
    EventHandler::EventHandler(engine::Board &b, gui::Window &w)
        : board(b), window(w)
    {
    }

    void EventHandler::processEvents(conf::Settings &settings)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    handleClick(event.mouseButton.x, event.mouseButton.y, settings.getSquareSize());
                }
            }
            break;
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
            break;
            }
        }
    }

    void EventHandler::handleClick(const int x, const int y, const unsigned int squareSize)
    {
        int row = y / squareSize;
        int col = x / squareSize;
        if (row < 0 || row > 7 || col < 0 || col > 7)
        {
            board.deselect();
            return;
        }
        if (board.getIsSelected())
        {
            board.deselect();
            if (board.validMove(board.getSelectedRow(), board.getSelectedCol(), row, col))
            {
                board.update(board.getSelectedRow(), board.getSelectedCol(), row, col);
                board.updateAttackBoard();
            }
        }
        else
        {
            if (board.getFigure(row, col).getColor() == board.getCurrentTurn())
            {
                board.select(row, col);
            }
        }
    }
}