#include "gui/window.hpp"
#include "gui/board_renderer.hpp"
#include "gui/event_handler.hpp"
#include "engine/board.hpp"
#include "gui/color_selector.hpp"
#include <iostream>

int main()
{
    gui::ColorSelector colorSelector;
    gui::SelectColor select;
    if ((select = colorSelector.run()) == gui::SelectColor::NONE)
    {
        std::cerr << "Failed to select a color.\n";
        return 1;
    }
    gui::Window window(800, 800, "Chess Engine");
    engine::Board board;
    if (select == gui::SelectColor::BLACK)
    {
        board.changeBoardSide();
    }
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