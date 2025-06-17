#include "gui/resources.hpp"

namespace gui
{
    Resources::Resources()
    {
        valid = loadTextures();
    }
    bool Resources::loadTextures()
    {
        overLayer.setSize({480, 120});
        overLayer.setPosition(400 - overLayer.getLocalBounds().width / 2, 400 - overLayer.getLocalBounds().height / 2);
        overLayer.setFillColor(sf::Color(200, 200, 200, 200));
        queenButton.setSize({100, 100});
        queenButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 10, 400 - queenButton.getLocalBounds().height / 2);
        queenButton.setFillColor(sf::Color(100, 100, 100, 200));
        queenFigure.setScale({0.1f, 0.1f});
        queenFigure.setPosition(400 - overLayer.getLocalBounds().width / 2 + 10, 400 - queenButton.getLocalBounds().height / 2);
        rookButton.setSize({100, 100});
        rookButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 130, 400 - rookButton.getLocalBounds().height / 2);
        rookButton.setFillColor(sf::Color(100, 100, 100, 200));
        rookFigure.setScale({0.1f, 0.1f});
        rookFigure.setPosition(400 - overLayer.getLocalBounds().width / 2 + 130, 400 - rookButton.getLocalBounds().height / 2);
        bishopButton.setSize({100, 100});
        bishopButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 250, 400 - bishopButton.getLocalBounds().height / 2);
        bishopButton.setFillColor(sf::Color(100, 100, 100, 200));
        bishopFigure.setScale({0.1f, 0.1f});
        bishopFigure.setPosition(400 - overLayer.getLocalBounds().width / 2 + 250, 400 - bishopButton.getLocalBounds().height / 2);
        knightButton.setSize({100, 100});
        knightButton.setPosition(400 - overLayer.getLocalBounds().width / 2 + 370, 400 - knightButton.getLocalBounds().height / 2);
        knightButton.setFillColor(sf::Color(100, 100, 100, 200));
        knightFigure.setScale({0.1f, 0.1f});
        knightFigure.setPosition(400 - overLayer.getLocalBounds().width / 2 + 370, 400 - knightButton.getLocalBounds().height / 2);

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

    bool Resources::isValid() const
    {
        return valid;
    }
    std::vector<const sf::Drawable *> Resources::getStartResources() const
    {
        return {&text, &buttonWhite, &buttonBlack, &textWhite, &textBlack};
    }
    std::vector<const sf::Drawable *> Resources::getGameResources() const
    {
        return {};
    }
    std::vector<const sf::Drawable *> Resources::getPromotionResources() const
    {
        return {&overLayer, &queenButton, &queenFigure, &rookButton, &rookFigure, &bishopButton, &bishopFigure, &knightButton, &knightFigure};
    }
    std::vector<const sf::Drawable *> Resources::getEndResources() const
    {
        return {};
    }
    void Resources::setPromotionWhite()
    {
        queenFigure.setTexture(pieceTextures["wq"]);
        rookFigure.setTexture(pieceTextures["wr"]);
        knightFigure.setTexture(pieceTextures["wn"]);
        bishopFigure.setTexture(pieceTextures["wb"]);
    }
    void Resources::setPromotionBlack()
    {
        queenFigure.setTexture(pieceTextures["bq"]);
        rookFigure.setTexture(pieceTextures["br"]);
        knightFigure.setTexture(pieceTextures["bn"]);
        bishopFigure.setTexture(pieceTextures["bb"]);
    }
    std::map<std::string, sf::Texture>::const_iterator Resources::atPieceTextures(std::string key) const
    {
        return pieceTextures.find(key);
    }
    bool Resources::whiteRectangleContains(float x, float y) const
    {
        return buttonWhite.getGlobalBounds().contains(x, y);
    }
    bool Resources::blackRectangleContains(float x, float y) const
    {
        return buttonBlack.getGlobalBounds().contains(x, y);
    }
}