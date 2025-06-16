#include "config/settings.hpp"
#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "gui/event_handler.hpp"
#include "engine/board.hpp"
#include "gui/color_selector.hpp"
#include "gui/state.hpp"
#include <iostream>

int main()
{
    gui::State currentState(gui::State::START);
    conf::Settings settings;
    gui::Window window(settings);
    if (!window.isValid())
    {
        std::cerr << "Failed to load textures.\n";
        return 1;
    }
    engine::Board board;
    gui::BoardRenderer boardRenderer(board, window, settings, currentState);
    gui::EventHandler eventHandler(board, window, settings, currentState);

    while (window.isOpen())
    {
        eventHandler.processEvents();
        window.clear(settings.getBackgroundColor());
        boardRenderer.draw();
        window.display();
    }

    return 0;
}