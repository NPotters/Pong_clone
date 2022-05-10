#include "PlayMenu.h"

PlayMenu::PlayMenuOptions PlayMenu::Show(sf::RenderWindow& window)
{
    //Load menu image
    sf::Texture image;
    image.loadFromFile("./Files/GameMode.png");
    sf::Sprite spritewindow(image);
    //sf::RectangleShape line(sf::Vector2f(1451, 280));
    //line.setPosition(241, 165);

    //Setup menu items
    //1Player menu button
    PlayMenuItem Play1Button;
    Play1Button.rect.top = 165;
    Play1Button.rect.left = 241;
    Play1Button.rect.width = 1451;
    Play1Button.rect.height = 280;
    Play1Button.action = Play1;

    //2player Menu button
    PlayMenuItem Play2Button;
    Play2Button.rect.top = 508;
    Play2Button.rect.left = 241;
    Play2Button.rect.width = 1451;
    Play2Button.rect.height = 280;
    Play2Button.action = Play2;

    //add to menu item list
    _playMenuItems.push_back(Play1Button);
    _playMenuItems.push_back(Play2Button);


    window.draw(spritewindow);
    //window.draw(line);
    window.display();
    return GetMenuResponse(window);//event loop for Menu
}

// buttons react top click or return nothing
PlayMenu::PlayMenuOptions PlayMenu::Handleclick(int x, int y)
{
    std::list<PlayMenuItem>::iterator it;
    for (it = _playMenuItems.begin(); it != _playMenuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;//point to menuitem from list
        if (menuItemRect.top < y
            && (menuItemRect.height + menuItemRect.top) > y
            && menuItemRect.left < x
            && (menuItemRect.width + menuItemRect.left) > x)
        {
            return (*it).action;
        }
    }
    return Nothing;
}

// response of menu
PlayMenu::PlayMenuOptions PlayMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event MenuEvent;
    while (1 != 2)//to freeze the menu when pressed esc.until mouseclick happened
    {
        while (window.pollEvent(MenuEvent))
        {
            if (MenuEvent.type == sf::Event::MouseButtonPressed)
            {
                return Handleclick(MenuEvent.mouseButton.x, MenuEvent.mouseButton.y);
            }
            if (MenuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
            if (MenuEvent.type == sf::Event::KeyPressed)
            {
                if (MenuEvent.key.code == sf::Keyboard::Escape)
                {
                    return GoBack;
                }
                return Nothing;
            }
        }
    }
}