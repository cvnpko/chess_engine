#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP

#include "config/settings.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace gui
{
    class Window
    {
    public:
        Window(conf::Settings &settings);
        bool isOpen() const;
        bool pollEvent(sf::Event &event);
        void clear(const sf::Color &color = sf::Color::White);
        void display();
        void close();
        void draw(const sf::Drawable &drawable);
        sf::Vector2i getMousePosition() const;
        void getSize(unsigned &width, unsigned &height);

    private:
        sf::RenderWindow window;
    };
}

#endif