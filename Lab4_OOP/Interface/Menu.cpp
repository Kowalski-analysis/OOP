#include "Menu.h"

Menu::Menu (float x, float y)
{
    _x = x;
    _y = y;
    _show = false;
    Button new_btn (*this, x, y);
    
}
float Menu::GetX () const
{
    return _x;
}
float Menu::GetY () const
{
    return _y;
}
void Menu::DrawMenu (sf::Window &window)
{

}
void Menu::DrawButtons(sf::Window &window)
{

}

Button::Button (Menu & M, float x, float y)
{
    _x_shift = M.GetX() - x;
    _y_shift = M.GetY() - y;
    _text = "";
    M.GetButtons().push_back(this);
}
float Button::GetXShift () const
{
    return _y_shift;
}
float Button::GetYShift () const
{
    return _y_shift;
}
std::vector <Button*> Menu::GetButtons ()
{
    return _buttons;
}
std::string Button::GetText ()
{
    return _text;
}
void Button::CheckButtons ()
{

}
