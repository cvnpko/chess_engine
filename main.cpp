#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "gui/event_handler.hpp"
#include "engine/board.hpp"

int main()
{
    gui::Window window(800, 800, "Chess Engine");
    engine::Board board;
    gui::BoardRenderer boardRenderer(board);
    gui::EventHandler eventHandler(board, window);

    while (window.isOpen())
    {
        eventHandler.processEvents();
        window.clear();
        boardRenderer.draw(window);
    }

    return 0;
}