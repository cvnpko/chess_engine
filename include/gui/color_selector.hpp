#ifndef COLOR_SELECTOR_HPP
#define COLOR_SELECTOR_HPP

#include <SFML/Graphics.hpp>
#include <window.hpp>

namespace gui
{
    class ColorSelector
    {
    public:
        int run();

    private:
        gui::Window window;
        sf::Font font;
        sf::Text text;
        sf::RectangleShape buttonWhite, buttonBlack;
        sf::Text textWhite, textBlack;

        void handleEvents(int &val);
        void render();
        void setup();
    };

}
#endif