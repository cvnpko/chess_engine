#ifndef COLOR_SELECTOR_HPP
#define COLOR_SELECTOR_HPP

#include <SFML/Graphics.hpp>
#include "gui/window.hpp"
#include "config/settings.hpp"

namespace gui
{
    enum SelectColor
    {
        NONE,
        WHITE,
        BLACK
    };
    class ColorSelector
    {
    public:
        ColorSelector(conf::Settings settings);
        SelectColor run();

    private:
        gui::Window window;
        sf::Font font;
        sf::Text text;
        sf::RectangleShape buttonWhite, buttonBlack;
        sf::Text textWhite, textBlack;

        void handleEvents(SelectColor &val);
        void render();
        void setup();
    };

}
#endif