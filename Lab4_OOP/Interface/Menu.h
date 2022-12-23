#ifndef MYPRIORITYQUEUE_MENU_H
#define MYPRIORITYQUEUE_MENU_H
#include "../World/World.h"
#include "SFML/Graphics.hpp"

class Menu
{
private:
    float _x;
    float _y;
    bool _show;
    bool _tower;
    bool _wall;
    friend World;
public:
    Menu (float x, float y);
    [[nodiscard]] float GetX () const;
    [[nodiscard]] float GetY () const;
    [[nodiscard]] bool GetShow () const;
    void DrawMenu (sf::RenderWindow &window) const;
    void CheckOpen (sf::RenderWindow &window);
    void CheckTower (sf::RenderWindow &window);
    void CheckWall (sf::RenderWindow &window);
    void CheckButtons (sf::RenderWindow &window);
    void NewTower (World &world, sf::RenderWindow &window);
    void NewWall(World &world, sf::RenderWindow &window);
};
#endif
