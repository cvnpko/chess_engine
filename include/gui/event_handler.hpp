#ifndef GUI_EVENT_HANDLER_HPP
#define GUI_EVENT_HANDLER_HPP

#include "engine/board.hpp"
#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "config/settings.hpp"
#include <SFML/Graphics.hpp>

namespace gui
{
    class EventHandler
    {
    public:
        EventHandler(engine::Board &board, gui::Window &window);
        void processEvents(conf::Settings &settings);

    private:
        engine::Board &board;
        gui::Window &window;
        bool pieceSelected = false;
        int selectedRow, selectedCol;
        sf::Vector2i selectedSquare;
        void handleEvent(const sf::Event &event);
        void handleClick(int x, int y, unsigned int squareSize);
        sf::Vector2i getBoardCoordinates(int x, int y) const;
    };
}

#endif