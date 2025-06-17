#ifndef GUI_BOARD_RENDERER_HPP
#define GUI_BOARD_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "config/settings.hpp"
#include "engine/board.hpp"
#include "gui/window.hpp"
#include "gui/state.hpp"
#include "gui/resources.hpp"

namespace gui
{
    class BoardRenderer
    {
    public:
        BoardRenderer(engine::Board &board, gui::Window &window, conf::Settings &settings, gui::State &currentState, gui::Resources &resources);
        void draw();

    private:
        engine::Board &board;
        gui::Window &window;
        gui::State &currentState;
        conf::Settings &settings;
        gui::Resources &resources;
        void drawSquares();
        void drawPieces();
        void drawStart();
        void drawPromotion();
        std::string getTextureKey(const engine::Figure &figure) const;
    };
}

#endif