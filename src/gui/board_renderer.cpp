#include "gui/board_renderer.hpp"

namespace gui
{
    BoardRenderer::BoardRenderer(const engine::Board &b)
        : board(b)
    {
    }
    void BoardRenderer::draw(gui::Window &window)
    {
        window.clear(sf::Color::White);
        window.display();
    }
}