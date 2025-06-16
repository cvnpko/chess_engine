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
        EventHandler(engine::Board &board, gui::Window &window, conf::Settings &settings);
        void processEvents();

    private:
        engine::Board &board;
        gui::Window &window;
        conf::Settings &settings;
        sf::Vector2i selectedSquare;
        void handleEvent(const sf::Event &event);
        void handleClick(int x, int y, unsigned int squareSize);
        void handleResize(unsigned width, unsigned height);
        sf::Vector2i getBoardCoordinates(int x, int y) const;
    };
}

#endif