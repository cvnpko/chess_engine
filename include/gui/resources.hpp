#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace gui
{
    class Resources
    {
    public:
        Resources();
        bool isValid() const;
        std::vector<const sf::Drawable *> getStartResources() const;
        std::vector<const sf::Drawable *> getGameResources() const;
        std::vector<const sf::Drawable *> getPromotionResources() const;
        std::vector<const sf::Drawable *> getEndResources() const;
        void setPromotionWhite();
        void setPromotionBlack();
        std::map<std::string, sf::Texture>::const_iterator atPieceTextures(std::string key) const;
        bool whiteRectangleContains(float x, float y) const;
        bool blackRectangleContains(float x, float y) const;

    private:
        sf::Font font;
        sf::Text text, textWhite, textBlack;
        sf::RectangleShape buttonWhite, buttonBlack;
        sf::RectangleShape overLayer, queenButton, rookButton, bishopButton, knightButton;
        sf::Sprite queenFigure, rookFigure, bishopFigure, knightFigure;
        std::map<std::string, sf::Texture> pieceTextures;
        bool valid;
        bool loadTextures();
    };
}

#endif