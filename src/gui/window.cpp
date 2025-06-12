#include "gui/window.hpp"

namespace gui
{
    Window::Window(conf::Settings &settings)
        : window(sf::VideoMode(settings.getCurrentWidth(), settings.getCurrentHeight()), settings.getTitle())
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