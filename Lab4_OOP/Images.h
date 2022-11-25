#ifndef LAB4_OOP_IMAGES_H
#define LAB4_OOP_IMAGES_H
#include <SFML/Graphics.hpp>

class Sprite
{
private:
    sf::Sprite _sprite;
    char _type_of_land;
    int _height;
    int _width;
public:
    Sprite();
    sf::Sprite GetSprite ();
    char GetTypeOfLand () const;
    int GetHeight () const;
    int GetWight () const;
};

#endif //LAB4_OOP_IMAGES_H
