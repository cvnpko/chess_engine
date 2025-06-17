#include "gui/board_renderer.hpp"
#include <vector>

namespace gui
{
    BoardRenderer::BoardRenderer(engine::Board &b, gui::Window &w, conf::Settings &s, gui::State &cs, gui::Resources &r)
        : board(b), window(w), settings(s), currentState(cs), resources(r)
    {
    }

    void BoardRenderer::draw()
    {
        switch (currentState)
        {
        case State::START:
            drawStart();
            break;
        case State::GAME:
            drawSquares();
            drawPieces();
            break;
        case State::PROMOTION:
            drawSquares();
            drawPieces();
            drawPromotion();
            break;
        case State::END:
            break;
        }
    }

    void BoardRenderer::drawPromotion()
    {
        if (board.getCurrentTurn() == engine::FigureColor::WHITE)
        {
            resources.setPromotionWhite();
        }
        else
        {
            resources.setPromotionBlack();
        }
        std::vector<const sf::Drawable *> vec = resources.getPromotionResources();
        for (auto &v : vec)
        {
            window.draw(*v);
        }
    }

    void BoardRenderer::drawStart()
    {
        std::vector<const sf::Drawable *> vec = resources.getStartResources();
        for (auto &v : vec)
        {
            window.draw(*v);
        }
    }

    void BoardRenderer::drawSquares()
    {
        float squareSize = settings.getSquareSize();
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        bool lightSquare = true;

        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                square.setPosition(col * squareSize, row * squareSize);
                if (!board.getFigure(row, col).getSelected())
                {
                    square.setFillColor(lightSquare ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
                }
                else
                {
                    square.setFillColor(sf::Color(211, 177, 140));
                }
                window.draw(square);
                lightSquare = !lightSquare;
            }
            lightSquare = !lightSquare;
        }
    }

    std::string BoardRenderer::getTextureKey(const engine::Figure &figure) const
    {
        if (figure.getType() == engine::FigureType::NONE)
        {
            return "";
        }
        std::string key;
        key += (figure.getColor() == engine::FigureColor::WHITE) ? 'w' : 'b';
        switch (figure.getType())
        {
        case engine::FigureType::PAWN:
            key += 'p';
            break;
        case engine::FigureType::ROOK:
            key += 'r';
            break;
        case engine::FigureType::KNIGHT:
            key += 'n';
            break;
        case engine::FigureType::BISHOP:
            key += 'b';
            break;
        case engine::FigureType::QUEEN:
            key += 'q';
            break;
        case engine::FigureType::KING:
            key += 'k';
            break;
        default:
            break;
        }
        return key;
    }

    void BoardRenderer::drawPieces()
    {
        float squareSize = settings.getSquareSize();
        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                const engine::Figure &figure = board.getFigure(row, col);
                if (figure.getType() == engine::FigureType::NONE)
                {
                    continue;
                }
                std::string key = getTextureKey(figure);
                if (key.empty())
                {
                    continue;
                }
                std::map<std::string, sf::Texture>::const_iterator it = resources.atPieceTextures(key);
                sf::Sprite sprite(it->second);
                const sf::Texture *texture = sprite.getTexture();
                if (texture)
                {
                    float texWidth = static_cast<float>(texture->getSize().x);
                    float texHeight = static_cast<float>(texture->getSize().y);
                    float scaleX = squareSize / texWidth;
                    float scaleY = squareSize / texHeight;
                    sprite.setScale(scaleX, scaleY);
                    sprite.setOrigin(texWidth / 2.f, texHeight / 2.f);
                    sprite.setPosition(col * squareSize + squareSize / 2.f, row * squareSize + squareSize / 2.f);
                }
                window.draw(sprite);
            }
        }
    }
}