#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Buildings.h"
#include "Entities.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    sf::Clock clock;
    World W(8, 20);
    W.GetField()[10][4]->A_star(W, *W.GetField()[11][4]);
//    Wall VV1(W, 3, 7);
//    Wall VV2(W, 4, 8);
//    Wall VV3(W, 4, 9);
//    Wall VV4(W, 5, 10);
//    Wall VV5(W, 5, 11);
//    Castle C(W, 4, 14);
//    Tower T(W, 6, 17);
//    Spawner S(W, 3, 6);
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
