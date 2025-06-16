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
        BoardRenderer(engine::Board &board, gui::Window &window, conf::Settings &settings);
        void draw();
        bool isValid() const;

    private:
        engine::Board &board;
        gui::Window &window;
        conf::Settings &settings;
        bool valid;
        std::map<std::string, sf::Texture> pieceTextures;
        bool loadTextures();
        void drawSquares();
        void drawPieces();
        std::string getTextureKey(const engine::Figure &figure) const;
    };
}

#endif