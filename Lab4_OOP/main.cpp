#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);

    sf::Image img;
    img.loadFromFile("../Textures/Land234.png");

    sf::Texture tex;
    tex.loadFromImage(img);

    sf::Sprite spt;
    spt.setTexture(tex);

    sf::Image img1;
    img1.loadFromFile("../Textures/Castle.png");

    sf::Texture tex1;
    tex1.loadFromImage(img1);

    sf::Sprite spt1;
    spt1.setTexture(tex1);

    sf::String map_land[10] = {
            "1111111111",
            "1        1",
            "1        1",
            "1        1",
            "1        1",
            "1        1",
            "1        1",
            "1        1",
            "1        1",
            "1111111111",
    };

    sf::String map_buildings[10] = {
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "          ",
            "      1   ",
            "          ",
            "          ",
            "          ",
    };

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                window.close();
        }

        window.clear();

        float q = 0;
        for (sf::String & i : map_land)
        {
            float x = 960 - q * 90 - 90;
            float y = q * 46 + 80;
            for (int j = 0; j < i.getSize(); ++j)
            {
                if (i[j] == '1')
                {
                    spt.setTextureRect(sf::IntRect(0,0,185,98));
                }
                else
                {
                    spt.setTextureRect(sf::IntRect(185,0,185,98));
                }
                spt.setPosition(x, y);
                x += 90;
                y += 46;
                window.draw(spt);
            }
            q += 1;
        }

        float q1 = 0;
        for (sf::String & i : map_buildings)
        {
            float x1 = 960 - q1 * 90 - 280 - 90 + 90;
            float y1 = q1 * 46 - 636 + 46 + 80;
            for (int j = 0; j < i.getSize(); ++j)
            {
                if (i[j] == '1')
                {
                    spt1.setTextureRect(sf::IntRect(0,0,560,780));
                    spt1.setPosition(x1, y1);
                    window.draw(spt1);
                }
                x1 += 90;
                y1 += 46;
            }
            q1 += 1;
        }

        window.display();
    }
    return 0;
}
