#ifndef MYPRIORITYQUEUE_MENU_H
#define MYPRIORITYQUEUE_MENU_H

#include <vector>
#include "SFML/Graphics.hpp"

class Button;

class Menu
{
private:
    float _x;
    float _y;
    std::vector <Button*> _buttons;
    bool _show;
public:
    Menu (float x, float y);
    [[nodiscard]] float GetX () const;
    [[nodiscard]] float GetY () const;
    std::vector <Button*> GetButtons ();
    void DrawMenu (sf::Window & window);
    void DrawButtons (sf::Window & window);
};

class Button
{
private:
    float _x_shift;
    float _y_shift;
    std::string _text;
public:
    Button (Menu & M, float x, float y);
    [[nodiscard]] float GetXShift () const;
    [[nodiscard]] float GetYShift () const;
    std::string GetText ();
    void CheckButtons ();
};

#endif
