#include "config/settings.hpp"
#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "gui/event_handler.hpp"
#include "engine/board.hpp"
#include "gui/resources.hpp"
#include "gui/state.hpp"
#include <iostream>

int main()
{
    conf::Settings settings;
    gui::Resources resources;
    if (!resources.isValid())
    {
        std::cerr << "Failed to load resources.\n";
        return 1;
    }
    gui::Window window(settings);
    engine::Board board;
    gui::State currentState(gui::State::PROMOTION);
    gui::BoardRenderer boardRenderer(board, window, settings, currentState, resources);
    gui::EventHandler eventHandler(board, window, settings, currentState, resources);

    while (window.isOpen())
    {
        eventHandler.processEvents();
        window.clear(settings.getBackgroundColor());
        boardRenderer.draw();
        window.display();
    }

    return 0;
}