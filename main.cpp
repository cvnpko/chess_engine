#include "config/settings.hpp"
#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "gui/event_handler.hpp"
#include "engine/board.hpp"
#include <iostream>

int main()
{
    conf::Settings settings;
    gui::Window window(settings);
    engine::Board board;
    gui::BoardRenderer boardRenderer(board);
    if (!boardRenderer.isValid())
    {
        std::cerr << "Failed to load textures in BoardRenderer constructor.\n";
        return 1;
    }
    gui::EventHandler eventHandler(board, window);

    while (window.isOpen())
    {
        eventHandler.processEvents();
        window.clear();
        boardRenderer.draw(window);
    }

    return 0;
}