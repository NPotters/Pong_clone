#include "StdAfx.h"
#include "StartScreen.h"

void Startscreen::Show(sf::RenderWindow& renderWindow)
{
    sf::Texture image;
    if (image.loadFromFile("./Files/IntroSpacePong.png") != true)
    {
        return;
    }

    sf::Sprite spritewindow(image);

    renderWindow.draw(spritewindow);
    renderWindow.display();

    sf::Event event;
    while (true)
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::KeyPressed
                || event.type == sf::Event::EventType::MouseButtonPressed
                || event.type == sf::Event::EventType::Closed)
            {
                return;
            }
        }
    }
}