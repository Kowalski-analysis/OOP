#include <ctime>
#include "World/World.h"
#include "Buildings/Buildings.h"
#include "Entities/Entities.h"
#include "Interface/Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    sf::Clock clock;
    Menu M(0, 0);
    World W(8, 20);
    W.GetField()[10][4]->A_star(W, *W.GetField()[11][4]);
    Knight K1(W, 3, 3);
    Knight K2(W, 7, 7);
    Wall VV1(W, 3, 7);
    Wall VV2(W, 4, 8);
    Wall VV3(W, 4, 9);
    Wall VV4(W, 5, 10);
    Wall VV5(W, 5, 11);
    Castle C(W, 4, 17);
    Spawner S(W, 2, 2);
    Tower T(W, 6, 17);
    W.GetField()[3][3]->A_star(W, *W.GetField()[14][5]);
    W.GetField()[7][7]->A_star(W, *W.GetField()[14][5]);
    clock_t time = std::clock();
    S.SpawnUnit(W, 'K');
    while (window.isOpen())
    {   time = std::clock();
        sf::Event event {};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            {
                window.close();
            }
        }
        window.clear();
        W.DrawLand(window);
        W.DrawEntities(window);
        W.DrawBuildings(window);
        M.CheckOpen(window);
        M.DrawMenu(window);
        window.display();
    }
    return 0;
}
