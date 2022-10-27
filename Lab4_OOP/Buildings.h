#ifndef LAB4_OOP_BUILDINGS_H
#define LAB4_OOP_BUILDINGS_H

typedef struct Coordinates
{
    int x;
    int y;
    int length_x;
    int length_y;
} Coordinates;

class Build
{
private:
    int hp;
    Coordinates Location;
    int level;
public:
    void TakeDamage();
};
class Castle : Build
{

};
class Tower : Build
{
private:
    int damage;
    double reload;
public:
    void DealDamage();
};
class Wall : Build
{

};
class Spawner : Build
{
private:
    double reload;
};

#endif //LAB4_OOP_BUILDINGS_H
