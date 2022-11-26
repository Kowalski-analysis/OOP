#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    World W(8);
//    W.GetField()[1][1]->A_star(W, *W.GetField()[1][3]);
    while (window.isOpen())
    {
        sf::Event event {};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                window.close();
        }
        window.clear();
        W.ReadMap();
        W.DrawLand(window);
        window.display();
    }
    return 0;
}
