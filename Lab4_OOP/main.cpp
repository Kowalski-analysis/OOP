#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);

//    sf::Image img;
//    img.loadFromFile("../Textures/Land234.png");
//
//    sf::Texture tex;
//    tex.loadFromImage(img);
//
//    sf::Sprite spt;
//    spt.setTexture(tex);
//
//    sf::Image img1;
//    img1.loadFromFile("../Textures/Castle.png");
//
//    sf::Texture tex1;
//    tex1.loadFromImage(img1);
//
//    sf::Sprite spt1;
//    spt1.setTexture(tex1);
//
//    std::string map_land[24] = {
//            "111111111111111111111",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "1                   1",
//            "                    1",
//            "111111111111111111111",
//    };
    World W(19);
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
//        for (int i = 0; i < map_land->size(); ++i)
//        {
//            float x = 0;
//            float y = (float)i * 46;
//            if (i % 2 == 1)
//            {
//                x += 90;
//            }
//            for (char j : map_land[i])
//            {
//                spt.setPosition(x, y);
//                x += 180;
//                if (j == '.')
//                {
//                    continue;
//                }
//                if (j == '1')
//                {
//                    spt.setTextureRect(sf::IntRect(0,0,185,98));
//                }
//                if (j == ' ')
//                {
//                    spt.setTextureRect(sf::IntRect(185,0,185,98));
//                }
//                window.draw(spt);
//            }
//        }

        W.DrawLand(window);
        window.display();
    }
    return 0;
}
