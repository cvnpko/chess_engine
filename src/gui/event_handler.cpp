#include "gui/event_handler.hpp"

namespace gui
{
    EventHandler::EventHandler(engine::Board &b, gui::Window &w, conf::Settings &s, gui::State &cs, gui::Resources &r)
        : board(b), window(w), settings(s), currentState(cs), resources(r)
    {
    }

    void EventHandler::processEvents()
    {
        sf::Event event;
        switch (currentState)
        {
        case gui::State::START:
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
                    sf::Vector2i mousePos = window.getMousePosition();
                    if (resources.whiteRectangleContains((float)mousePos.x, (float)mousePos.y))
                    {
                        currentState = gui::State::GAME;
                    }
                    if (resources.blackRectangleContains((float)mousePos.x, (float)mousePos.y))
                    {
                        currentState = gui::State::GAME;
                        board.changeBoardSide();
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
            break;
        case gui::State::GAME:
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
            break;
        case gui::State::PROMOTION:
            break;
        case gui::State::END:
            break;
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
            board.validMove(board.getSelectedRow(), board.getSelectedCol(), row, col);
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