#include "gui/color_selector.hpp"

namespace gui
{
    ColorSelector::ColorSelector(conf::Settings settings) : window(settings) {}
    SelectColor ColorSelector::run()
    {
        SelectColor select = NONE;
        //if (!font.loadFromFile("assets/fonts/arial.ttf"))
        if(!font.loadFromFile("D:\\Projects\\GitHub\\chess_engine\\assets\\fonts\\arial.ttf"))
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