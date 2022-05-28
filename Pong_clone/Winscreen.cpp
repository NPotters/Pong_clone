#include "Winscreen.h"
#include "Score.h"

void Winscreen::Show(sf::RenderWindow& renderWindow)
{
    sf::Texture image;
    if (_n > _p)
    {
        if (image.loadFromFile("./Files/Win_Blue.png") != true)
        {
            return;
        }
    }
    if (_n < _p)
    {
        if (image.loadFromFile("./Files/Win_Pink.png") != true)
        {
            return;
        }
    }
   

    sf::Sprite spritewindow(image);

    renderWindow.draw(spritewindow);
    renderWindow.display();

    sf::Event event;
    while (true)
    {
        while (renderWindow.pollEvent(event))
        {
            if ((event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Enter)
                || event.type == sf::Event::EventType::Closed)
            {
                return;
            }
        }
    }
}