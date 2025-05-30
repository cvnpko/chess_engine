#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace gui
{
    class Window
    {
    public:
        Window(unsigned int width, unsigned int height, const std::string &title);
        bool isOpen() const;
        bool pollEvent(sf::Event &event);
        void clear(const sf::Color &color = sf::Color::White);
        void display();
        void close();
        void draw(const sf::Drawable &drawable);
        sf::Vector2i getMousePosition() const;
        sf::RenderWindow &getRawWindow();

    private:
        sf::RenderWindow window;
    };

}

#endif