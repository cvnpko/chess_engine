#include "gui/color_selector.hpp"

namespace gui
{
    ColorSelector::ColorSelector() : window(400, 200, "Select a color") {}
    SelectColor ColorSelector::run()
    {
        SelectColor select = NONE;
        if (!font.loadFromFile("assets/fonts/arial.ttf"))
        {
            return select;
        }
        setup();
        while (window.isOpen())
        {
            handleEvents(select);
            render();

            if (select != SelectColor::NONE)
            {
                window.close();
            }
        }
        return select;
    }
    void ColorSelector::setup()
    {
        text.setFont(font);
        text.setString("Select a color:");
        text.setCharacterSize(24);
        text.setPosition(120, 20);

        buttonWhite.setSize({100, 50});
        buttonWhite.setPosition(50, 100);
        buttonWhite.setFillColor(sf::Color::White);
        buttonWhite.setOutlineColor(sf::Color::Black);
        buttonWhite.setOutlineThickness(2);

        textWhite.setFont(font);
        textWhite.setString("White");
        textWhite.setCharacterSize(20);
        textWhite.setFillColor(sf::Color::Black);
        textWhite.setPosition(75, 110);

        buttonBlack.setSize({100, 50});
        buttonBlack.setPosition(250, 100);
        buttonBlack.setFillColor(sf::Color::Black);
        buttonBlack.setOutlineColor(sf::Color::White);
        buttonBlack.setOutlineThickness(2);

        textBlack.setFont(font);
        textBlack.setString("Black");
        textBlack.setCharacterSize(20);
        textBlack.setFillColor(sf::Color::White);
        textBlack.setPosition(275, 110);
    }

    void ColorSelector::handleEvents(SelectColor &val)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = window.getMousePosition();
                if (buttonWhite.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
                {
                    val = WHITE;
                }
                if (buttonBlack.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y))
                {
                    val = BLACK;
                }
            }
        }
    }

    void ColorSelector::render()
    {
        window.clear(sf::Color(100, 100, 100));
        window.draw(text);
        window.draw(buttonWhite);
        window.draw(textWhite);
        window.draw(buttonBlack);
        window.draw(textBlack);
        window.display();
    }
}