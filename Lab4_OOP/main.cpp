#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    World W(8, 20);
    W.GetField()[1][1]->A_star(W, *W.GetField()[8][8]);
    sf::Clock clock;
    while (window.isOpen())
    {
        long long time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;
        sf::Event event {};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                window.close();
        }
        window.clear();
        W.DrawLand(window);
        W.DrawBuildings(window);
        window.display();
    }
    return 0;
}
