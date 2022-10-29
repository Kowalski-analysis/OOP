#include "Buildings.h"

Building::Building () : hp(0), max_hp(0), level(1), level_max(5)
{
}
Building::Building (int x, int y) : Building()
{
    Location.x = x;
    Location.y = y;
}
void Building::TakeDamage (int damage)
{
    if (this->hp <= damage)
    {
        this->hp = 0;
    }
    else
    {
        this->hp -= damage;
    }
}
void Building::Heal ()
{
    if (max_hp - hp < 100)
    {
        hp = max_hp;
        return;
    }
    hp += 100;
}
void Building::Destroy ()
{
    if (hp <= 0)
    {

    }
}

Castle::Castle ()
{
    hp = 1000;
    max_hp = 1000;
    Location.length_x = 2;
    Location.length_y = 2;
}
int Castle::LevelUp ()
{
    if (level == level_max)
    {
        return 1;
    }
    ++level;
    max_hp += 100;
    hp += 100;
    return 0;
}

Tower::Tower ()
{
    hp = 100;
    max_hp = 100;
    Location.length_y = 2;
    Location.length_x = 2;
    damage = 30;
    reload = 2;
}
int Tower::DealDamage () const
{
    return damage;
}
int Tower::LevelUp ()
{
    if (level == level_max)
    {
        return 1;
    }
    ++level;
    if (level == 4)
    {
        reload = 1;
    }
    damage += 10;
    max_hp += 100;
    hp += 100;
    return 0;
}

int Wall::LevelUp ()
{
    if (level == level_max)
    {
        return 1;
    }
    ++level;
    max_hp += 200;
    hp += 200;
    return 0;
}

Spawner::Spawner ()
{
    hp = 1;
    max_hp = 1;
    count_troop = 1;
    reload = 10;
}
int Spawner::LevelUp ()
{
    if (level == level_max)
    {
        return 1;
    }
    ++level;
    if (level % 2 == 0)
    {
        ++count_troop;
    }
    if (level == 4)
    {
        --reload;
    }
    return 0;
}

