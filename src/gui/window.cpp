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
    void Window::drawOverLayer(bool shouldWhite)
    {
        window.draw(overLayer);
        window.draw(queenButton);
        window.draw(rookButton);
        window.draw(knightButton);
        window.draw(bishopButton);
        if (shouldWhite)
        {
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("wq");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(queenButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("wr");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(rookButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("wn");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(knightButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("wb");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(bishopButton.getPosition());
                }
                window.draw(sprite);
            }
        }
        else
        {
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("bq");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(queenButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("br");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(rookButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("bn");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(knightButton.getPosition());
                }
                window.draw(sprite);
            }
            {
                std::map<std::string, sf::Texture>::const_iterator it = atPieceTextures("bb");
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = 100.0f / texWidth;
                    float scaleY = 100.0f / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setPosition(bishopButton.getPosition());
                }
                window.draw(sprite);
            }
        }
    }
    bool Window::loadTextures()
    {
        overLayer.setSize({480, 120});
        overLayer.setPosition(400 - overLayer.getLocalBounds().width / 2, 400 - overLayer.getLocalBounds().height / 2);
        overLayer.setFillColor(sf::Color(200, 200, 200, 200));
        queenButton.setSize({100, 100});
        queenButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 10, 400 - queenButton.getLocalBounds().height / 2);
        queenButton.setFillColor(sf::Color(100, 100, 100, 200));
        rookButton.setSize({100, 100});
        rookButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 130, 400 - rookButton.getLocalBounds().height / 2);
        rookButton.setFillColor(sf::Color(100, 100, 100, 200));
        bishopButton.setSize({100, 100});
        bishopButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 250, 400 - bishopButton.getLocalBounds().height / 2);
        bishopButton.setFillColor(sf::Color(100, 100, 100, 200));
        knightButton.setSize({100, 100});
        knightButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 370, 400 - knightButton.getLocalBounds().height / 2);
        knightButton.setFillColor(sf::Color(100, 100, 100, 200));

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
        return buttonWhite.getGlobalBounds().contains(x, y);
    }
    bool Window::blackRectangleContains(float x, float y) const
    {
        return buttonBlack.getGlobalBounds().contains(x, y);
    }

}