#include "gui/window.hpp"

namespace gui
{
    Window::Window(unsigned int width, unsigned int height, const std::string &title)
        : window(sf::VideoMode(width, height), title)
    {
        window.setFramerateLimit(60);
    }
    bool Window::isOpen() const
    {
        return window.isOpen();
    }
    bool Window::pollEvent(sf::Event &event)
    {
        return window.pollEvent(event);
    }
    void Window::clear(const sf::Color &color)
    {
        window.clear(color);
    }
    void Window::display()
    {
        window.display();
    }
    void Window::close()
    {
        window.close();
    }
    void Window::draw(const sf::Drawable &drawable)
    {
        window.draw(drawable);
    }
}