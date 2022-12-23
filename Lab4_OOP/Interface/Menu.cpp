#include "Menu.h"

Menu::Menu (float x, float y)
{
    _x = x;
    _y = y;
    _show = false;
    _tower = false;
    _wall = false;
}
float Menu::GetX () const
{
    return _x;
}
float Menu::GetY () const
{
    return _y;
}
bool Menu::GetShow () const
{
    return _show;
}
void Menu::DrawMenu (sf::RenderWindow &window) const
{
    if (_show)
    {
        sf::Image img;
        img.loadFromFile("../Textures/Menu.png");

        sf::Texture tex;
        tex.loadFromImage(img);

        sf::Sprite spt;
        spt.setTexture(tex);
        spt.setTextureRect(sf::IntRect(0,0,400,1080));
        spt.setPosition(GetX(), GetY());
        window.draw(spt);
    }
    else
    {
        sf::Image img;
        img.loadFromFile("../Textures/VButton.png");

        sf::Texture tex;
        tex.loadFromImage(img);

        sf::Sprite spt;
        spt.setTexture(tex);
        spt.setTextureRect(sf::IntRect(0,0,100,100));
        spt.setPosition(GetX(), GetY());
        window.draw(spt);
    }
}
void Menu::CheckOpen (sf::RenderWindow &window)
{
    sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
    if (pixel_pos.x >= 0 && pixel_pos.x <= 100 && pixel_pos.y >= 0 && pixel_pos.y <= 100 &&
    sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _show = !_show;
    }
}
void Menu::CheckTower (sf::RenderWindow &window)
{
    sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
    if (pixel_pos.x >= 14 && pixel_pos.x <= 383 && pixel_pos.y >= 344 && pixel_pos.y <= 684 &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && _show)
    {
        _tower = !_tower;
    }
}
void Menu::CheckWall (sf::RenderWindow &window)
{
    sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
    if (pixel_pos.x >= 14 && pixel_pos.x <= 385 && pixel_pos.y >= 725 && pixel_pos.y <= 1063 &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && _show)
    {
        _wall = !_wall;
    }
}
void Menu::CheckButtons (sf::RenderWindow &window)
{
    CheckOpen(window);
    CheckTower(window);
    CheckWall(window);
}
void Menu::NewTower (World &world, sf::RenderWindow &window)
{
}
void Menu::NewWall (World &world, sf::RenderWindow &window)
{
    if (_wall && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
        if (!world.GetField()[pixel_pos.y % 44][pixel_pos.x % 176]->GetLock())
        {

        }
    }
}


