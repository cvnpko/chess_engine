#include "gui/window.hpp"

namespace gui
{
    Window::Window(conf::Settings &settings)
        : window(sf::VideoMode(settings.getCurrentWidth(), settings.getCurrentHeight()),
                 settings.getTitle(), sf::Style::Titlebar | sf::Style::Close)
    {
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
    }
    void Window::getSize(unsigned &width, unsigned &height)
    {
        sf::Vector2u currentSize = window.getSize();
        width = currentSize.x, height = currentSize.y;
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