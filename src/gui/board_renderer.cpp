#include "gui/board_renderer.hpp"

namespace gui
{

    Board_Renderer::Board_Renderer(const engine::Board &b)
        : board(b)
    {
    }

    void Board_Renderer::draw(gui::Window &window)
    {
        window.clear(sf::Color::White);
        window.display();
    }

}