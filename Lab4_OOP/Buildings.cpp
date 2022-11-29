#include "Buildings.h"
#include "World.h"
#include "Entities.h"

std::string map_buildings[22] = {
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "     a    ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
        "          ",
};

Building::Building () : _hp(0), _max_hp(0), _level(1), _level_max(5)
{
}
void Building::TakeDamage (int damage)
{
    if (_hp <= damage)
    {
        _hp = 0;
    }
    else
    {
        _hp -= damage;
    }
}
void Building::Heal ()
{
    if (_max_hp - _hp < 100)
    {
        _hp = _max_hp;
        return;
    }
    _hp += 100;
}
void Building::Destroy ()
{
    if (_hp <= 0)
    {

    }
}
void Building::SetBuildingType ()
{
    _building_type = map_buildings[GetCurrentCell()->GetY()][GetCurrentCell()->GetX()];
}
Cell* Building::GetCurrentCell ()
{
    return _location;
}
char Building::GetBuildingType ()
{
    return _building_type;
}

Castle::Castle ()
{
    _hp = 1000;
    _max_hp = 1000;
}
int Castle::LevelUp ()
{
    if (_level == _level_max)
    {
        return 1;
    }
    ++_level;
    _max_hp += 100;
    _hp += 100;
    return 0;
}

void Castle::CheckEntities (World & world)
{
    for (auto & i : world.GetEntities())
    {
        if (i.second->GetCurCell()->GetManhattanDistance(*_location) <= 2)
        {
            TakeDamage(i.second->GetDamage());
            i.second->TakeDamage(i.second->GetHp());
            i.second->Die(world);
        }
    }
}

Tower::Tower ()
{
    _hp = 100;
    _max_hp = 100;
    _damage = 30;
    _reload = 2;
}
int Tower::GetDamage () const
{
    return _damage;
}
int Tower::GetRadius () const
{
    return _radius;
}
void Tower::FindTargets (World & world)
{
    for (std::pair <int, Warrior*> ent : world.GetEntities())
    {
        int dist = ent.second->GetCurCell()->GetNextCell()->GetManhattanDistance(*_location);
        if (dist <= _radius)
        {
            _targets.emplace(dist + ent.second->GetHp(), ent.second);
        }
    }
}
void Tower::DealDamage (Warrior & warrior) const
{
    warrior.TakeDamage(_damage);
}
int Tower::LevelUp ()
{
    if (_level == _level_max)
    {
        return 1;
    }
    ++_level;
    if (_level == 4)
    {
        _reload = 1;
    }
    _damage += 10;
    _max_hp += 100;
    _hp += 100;
    return 0;
}

int Wall::LevelUp ()
{
    if (_level == _level_max)
    {
        return 1;
    }
    ++_level;
    _max_hp += 200;
    _hp += 200;
    return 0;
}

Spawner::Spawner ()
{
    _hp = 1;
    _max_hp = 1;
    _count_troop = 1;
    _reload = 10;
}
int Spawner::LevelUp ()
{
    if (_level == _level_max)
    {
        return 1;
    }
    ++_level;
    if (_level % 2 == 0)
    {
        ++_count_troop;
    }
    if (_level == 4)
    {
        --_reload;
    }
    return 0;
}

