#ifndef GUI_BOARD_RENDERER_HPP
#define GUI_BOARD_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "config/settings.hpp"
#include "engine/board.hpp"
#include "gui/window.hpp"
#include "gui/state.hpp"

namespace gui
{
    class BoardRenderer
    {
    public:
        BoardRenderer(engine::Board &board, gui::Window &window, conf::Settings &settings, gui::State &currentState);
        void draw();

    private:
        engine::Board &board;
        gui::Window &window;
        gui::State &currentState;
        conf::Settings &settings;
        void drawSquares();
        void drawPieces();
        std::string getTextureKey(const engine::Figure &figure) const;
    };
}

#endif