#ifndef GUI_EVENT_HANDLER_HPP
#define GUI_EVENT_HANDLER_HPP

#include "engine/board.hpp"
#include "gui/window.hpp"
#include <SFML/Graphics.hpp>

namespace gui
{
    class EventHandler
    {
    public:
        EventHandler(engine::Board &board, gui::Window &window);
        void processEvents();

    private:
        engine::Board &board;
        gui::Window &window;
        float squareSize = 100.0f;
        bool pieceSelected = false;
        sf::Vector2i selectedSquare;
        void handleEvent(const sf::Event &event);
        sf::Vector2i getBoardCoordinates(int x, int y) const;
    };
}

#endif