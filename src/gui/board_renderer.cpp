#include "gui/board_renderer.hpp"
#include <stdexcept>

namespace gui
{
    BoardRenderer::BoardRenderer(const engine::Board &b)
        : board(b)
    {
        if (!loadTextures())
        {
            valid = false;
        }
    }
    bool BoardRenderer::isValid() const
    {
        return valid;
    }
    bool BoardRenderer::loadTextures()
    {
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

    void BoardRenderer::draw(gui::Window &window)
    {
        drawSquares(window);
        drawPieces(window);
        window.display();
    }

    void BoardRenderer::drawSquares(gui::Window &window)
    {
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        bool lightSquare = true;

        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                square.setPosition(col * squareSize, row * squareSize);
                square.setFillColor(lightSquare ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));
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

    void BoardRenderer::drawPieces(gui::Window &window)
    {
        const engine::Figure(&grid)[8][8] = board.getBoardGrid();
        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                const engine::Figure &figure = grid[row][col];
                std::string key = getTextureKey(figure);
                if (key.empty())
                {
                    continue;
                }
                auto it = pieceTextures.find(key);
                if (it == pieceTextures.end())
                {
                    continue;
                }
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