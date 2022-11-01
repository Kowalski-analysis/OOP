#ifndef LAB4_OOP_BUILDINGS_H
#define LAB4_OOP_BUILDINGS_H

#include <queue>
#include "Entities.h"

typedef struct Coordinates
{
    int x = 0;
    int y = 0;
    int length_x = 0;
    int length_y = 0;
} Coordinates;

class Building
{
protected:
    int hp;
    int max_hp;
    Coordinates Location;
    int level;
    int level_max;
public:
    Building ();
    Building (int x, int y);
    void Heal ();
    void TakeDamage (int damage);
    virtual int LevelUp () = 0;
    void Destroy ();
};
class Castle : public Building
{
public:
    Castle();
    int LevelUp() override;
};
class Tower : public Building
{
private:
    int damage;
    double reload;
    std::queue <Warrior &> targets;
public:
    Tower();
    [[nodiscard]] int DealDamage () const;
    int LevelUp() override;
};
class Wall : public Building
{
public:
    int LevelUp() override;
};
class Spawner : public Building
{
private:
    int count_troop;
    double reload;
public:
    Spawner();
    int LevelUp() override;
};

#endif //LAB4_OOP_BUILDINGS_H
