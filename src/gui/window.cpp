#include "gui/window.hpp"

namespace gui
{
    Window::Window(conf::Settings &settings)
        : window(sf::VideoMode(settings.getCurrentWidth(), settings.getCurrentHeight()),
                 settings.getTitle(), sf::Style::Titlebar | sf::Style::Close)
    {
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        valid = loadTextures();
    }
    bool Window::isValid() const
    {
        return valid;
    }
    bool Window::loadTextures()
    {
        if (!font.loadFromFile("assets/fonts/arial.ttf"))
        {
            return false;
        }
        text.setFont(font);
        text.setString("Select a color:");
        text.setCharacterSize(80);
        text.setPosition(400 - text.getLocalBounds().width / 2, 100);

        buttonWhite.setSize({400, 200});
        buttonWhite.setPosition(400 - buttonWhite.getLocalBounds().width / 2, 500);
        buttonWhite.setFillColor(sf::Color::White);
        buttonWhite.setOutlineColor(sf::Color::Black);
        buttonWhite.setOutlineThickness(2);

        textWhite.setFont(font);
        textWhite.setString("White");
        textWhite.setCharacterSize(70);
        textWhite.setFillColor(sf::Color::Black);
        textWhite.setPosition(400 - textWhite.getLocalBounds().width / 2, 550);

        buttonBlack.setSize({400, 200});
        buttonBlack.setPosition(400 - buttonBlack.getLocalBounds().width / 2, 250);
        buttonBlack.setFillColor(sf::Color::Black);
        buttonBlack.setOutlineColor(sf::Color::White);
        buttonBlack.setOutlineThickness(2);

        textBlack.setFont(font);
        textBlack.setString("Black");
        textBlack.setCharacterSize(70);
        textBlack.setFillColor(sf::Color::White);
        textBlack.setPosition(400 - textBlack.getLocalBounds().width / 2, 300);
        const std::vector<std::string> pieces = {
            "wp", "wr", "wn", "wb", "wq", "wk",
            "bp", "br", "bn", "bb", "bq", "bk"};
        for (const auto &key : pieces)
        {
            sf::Texture texture;
            std::string path = "assets/images/chess_sets/default/" + key + ".png";
            if (!texture.loadFromFile(path))
            {
                return false;
            }
            pieceTextures[key] = std::move(texture);
        }
        return true;
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
    sf::Vector2i Window::getMousePosition() const
    {
        return sf::Mouse::getPosition(window);
    }
    sf::Text Window::getText() const
    {
        return text;
    }
    sf::Text Window::getTextWhite() const
    {
        return textWhite;
    }
    sf::Text Window::getTextBlack() const
    {
        return textBlack;
    }
    sf::RectangleShape Window::getButtonWhite() const
    {
        return buttonWhite;
    }
    sf::RectangleShape Window::getButtonBlack() const
    {
        return buttonBlack;
    }
    std::map<std::string, sf::Texture>::const_iterator Window::atPieceTextures(std::string key) const
    {
        return pieceTextures.find(key);
    }
    void Window::drawStart()
    {
        draw(text);
        draw(buttonBlack);
        draw(buttonWhite);
        draw(textWhite);
        draw(textBlack);
    }
    bool Window::whiteRectangleContains(float x, float y) const
    {
        return buttonBlack.getGlobalBounds().contains(x, y);
    }
    bool Window::blackRectangleContains(float x, float y) const
    {
        return buttonBlack.getGlobalBounds().contains(x, y);
    }

}