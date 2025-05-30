#ifndef GUI_BOARD_RENDERER_HPP
#define GUI_BOARD_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "engine/board.hpp"
#include "gui/window.hpp"

namespace gui
{
    class Board_Renderer
    {
    public:
        Board_Renderer(const engine::Board &board);
        void draw(gui::Window &window);

    private:
        const engine::Board &board;
        float squareSize = 100.0f;
        std::map<std::string, sf::Texture> pieceTextures;
        void loadTextures();
        void drawSquares(gui::Window &window);
        void drawPieces(gui::Window &window);
    };
}
#endif