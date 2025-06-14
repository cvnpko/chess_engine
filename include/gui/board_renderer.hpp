#ifndef GUI_BOARD_RENDERER_HPP
#define GUI_BOARD_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "config/settings.hpp"
#include "engine/board.hpp"
#include "gui/window.hpp"

namespace gui
{
    class BoardRenderer
    {
    public:
        BoardRenderer(engine::Board &board);
        void draw(gui::Window &window, conf::Settings &settings);
        bool isValid() const;

    private:
        engine::Board &board;
        bool valid;
        std::map<std::string, sf::Texture> pieceTextures;
        bool loadTextures();
        void drawSquares(gui::Window &window, float squareSize);
        void drawPieces(gui::Window &window, float squareSize);
        std::string getTextureKey(const engine::Figure &figure) const;
    };
}

#endif