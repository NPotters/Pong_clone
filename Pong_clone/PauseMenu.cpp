#include "PauseMenu.h"

PauseMenu::PauseMenuOptions PauseMenu::Show(sf::RenderWindow& window)
{
    //Load menu image
    sf::Texture image;
    image.loadFromFile("./Files/Pause_Menu.png");
    sf::Sprite spritewindow(image);
    //sf::RectangleShape line(sf::Vector2f(1451, 280));
    //line.setPosition(241, 165);

    window.draw(spritewindow);
    //window.draw(line);
    window.display();
    return GetMenuResponse(window);//event loop for Menu
}

// response of menu
PauseMenu::PauseMenuOptions PauseMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event PauseMenuEvent;
    while (true)//to freeze the menu when pressed esc.until mouseclick happened
    {
        while (window.pollEvent(PauseMenuEvent))
        {
            if (PauseMenuEvent.type == sf::Event::KeyPressed)
            {
                if (PauseMenuEvent.key.code == sf::Keyboard::Space)
                {
                    return Return;
                }
            }
            if (PauseMenuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}