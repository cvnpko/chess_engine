#ifndef GUI_BOARD_RENDERER_HPP
#define GUI_BOARD_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "engine/board.hpp"
#include "gui/window.hpp"

namespace gui
{
    class BoardRenderer
    {
    public:
        BoardRenderer(const engine::Board &board);
        void draw(gui::Window &window);
        bool isValid() const;

    private:
        const engine::Board &board;
        float squareSize = 100.0f;
        bool valid = true;
        std::map<std::string, sf::Texture> pieceTextures;
        bool loadTextures();
        void drawSquares(gui::Window &window);
        void drawPieces(gui::Window &window);
        std::string getTextureKey(const engine::Figure &figure) const;
    };
}

#endif