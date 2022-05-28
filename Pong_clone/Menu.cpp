#include "Menu.h"

Menu::MenuOptions Menu::Show(sf::RenderWindow& window)
{
    //Load menu image
    sf::Texture image;
    image.loadFromFile("./Files/Menu.png");
    sf::Sprite spritewindow(image);
    //sf::RectangleShape line(sf::Vector2f(1451, 280));
    //line.setPosition(241, 165);
    //Setup menu items
    //Play menu button
    MenuItem PlayButton;
    PlayButton.rect.top = 165;
    PlayButton.rect.left = 241;
    PlayButton.rect.width = 1451;
    PlayButton.rect.height = 280;
    PlayButton.action = Play;
   // PlayButton.load = LoadPlay;

    //Exit Menu button
    MenuItem ExitButton;
    ExitButton.rect.top = 508;
    ExitButton.rect.left = 241;
    ExitButton.rect.width = 1451;
    ExitButton.rect.height = 280;
    ExitButton.action = Exit;
   // ExitButton.load = LoadExit;

    //add to menu item list
    _menuItems.push_back(PlayButton);
    _menuItems.push_back(ExitButton);

    //PinkGlow* glowpink = new PinkGlow();

    
    window.draw(spritewindow);
    //window.draw(line);
    window.display();
    return GetMenuResponse(window);//event loop for Menu
}

// buttons react top click or return nothing
Menu::MenuOptions Menu::Handleclick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;//point to menuitem from list
        if(menuItemRect.top < y
            && (menuItemRect.height + menuItemRect.top) > y
            && menuItemRect.left < x
            && (menuItemRect.width + menuItemRect.left) > x)
            { return (*it).action;}
    }
    return Nothing;
}

// buttons react top click or return nothing
/*Menu::MenuOptions Menu::HandleHover(int x, int y)
{
    std::list<MenuItem>::iterator it;
    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;//point to menuitem from list
        if (menuItemRect.top < y
            && (menuItemRect.height + menuItemRect.top) > y
            && menuItemRect.left < x
            && (menuItemRect.width + menuItemRect.left) > x)
        {
            return (*it).load;
        }
    }
    return Nothing;
}*/

// response of menu
Menu::MenuOptions Menu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event MenuEvent;

    while (true)//to freeze the menu when pressed esc.until mouseclick happened
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
        }
    }
   
}
/*
Menu::MenuOptions Menu::GetMenuHover(sf::RenderWindow& window)
{
    sf::Event MenuHover;
    while (window.pollEvent(MenuHover))
    {
        if (MenuHover.type == sf::Event::MouseMoved)
        {
            return HandleHover(MenuHover.mouseMove.x, MenuHover.mouseMove.y);
        }
    }
}*/


