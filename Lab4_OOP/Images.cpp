#include "Images.h"


sf::Sprite Sprite::GetSprite()
{
    return _sprite;
}
char Sprite::GetTypeOfLand() const
{
    return _type_of_land;
}
int Sprite::GetHeight() const
{
    return _height;
}
int Sprite::GetWight() const
{
    return _width;
}

Sprite::Sprite ()
{

}
