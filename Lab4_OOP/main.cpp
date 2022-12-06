#include <iostream>
#include "World/World.h"
#include "Buildings/Buildings.h"
#include "Entities/Entities.h"
#include "windows.h"
#include "MyPriorityQueue/priority_queue.h"

int main()
{
//    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
//    sf::Clock clock;
//    World W(8, 20);
//    W.GetField()[10][4]->A_star(W, *W.GetField()[11][4]);
//    Knight K1(W, 1, 1);
//    Knight K2(W, 7, 7);
//    Wall VV1(W, 3, 7);
//    Wall VV2(W, 4, 8);
//    Wall VV3(W, 4, 9);
//    Wall VV4(W, 5, 10);
//    Wall VV5(W, 5, 11);
//    Castle C(W, 4, 14);
//    Tower T(W, 6, 17);
//    Spawner S(W, 3, 6);
//    W.GetField()[1][1]->A_star(W, *W.GetField()[17][5]);
//    W.GetField()[7][7]->A_star(W, *W.GetField()[16][8]);
//    int i = 0;
//    while (window.isOpen())
//    {
//        ++i;
//        float time = (float)clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time /= 800;
//        sf::Event event {};
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
//            {
//                window.close();
//            }
//        }
//        window.clear();
//        W.DrawLand(window);
//        W.DrawEntities(window, time);
//        W.DrawBuildings(window);
//        window.display();
//        if (i == 44)
//        {
//            K1.Move();
//            K2.Move();
//            i = 0;
//        }
//    }

    My_Priority_Queue <int> Q;
    Q.Push(123, 4);
    std::cout << Q.IsEmpty();
    std::cout << Q.Top();
    return 0;
}
