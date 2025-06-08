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
        }
    }
}