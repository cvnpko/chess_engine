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
        void drawStart();
        void draw(const sf::Drawable &drawable);
        sf::Vector2i getMousePosition() const;
        void getSize(unsigned &width, unsigned &height);
        bool isValid() const;
        sf::Text getText() const;
        sf::Text getTextWhite() const;
        sf::Text getTextBlack() const;
        sf::RectangleShape getButtonWhite() const;
        sf::RectangleShape getButtonBlack() const;
        std::map<std::string, sf::Texture>::const_iterator atPieceTextures(std::string key) const;
        bool whiteRectangleContains(float x, float y) const;
        bool blackRectangleContains(float x, float y) const;

    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text text;
        sf::RectangleShape buttonWhite, buttonBlack;
        sf::Text textWhite, textBlack;
        bool valid;
        std::map<std::string, sf::Texture> pieceTextures;
        bool loadTextures();
    };
}

#endif