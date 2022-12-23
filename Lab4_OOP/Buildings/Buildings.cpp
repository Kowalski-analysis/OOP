#include "Buildings.h"
#include "../World/World.h"
#include "../Entities/Entities.h"

Building::Building () : _hp(0), _max_hp(0), _level(1), _level_max(5)
{
    _building_type = ' ';
    _location = nullptr;
    _id = 0;
}
int Building::GetId() const
{
    return _id;
}
Cell* Building::GetCurCell ()
{
    return _location;
}
char Building::GetBuildingType () const
{
    return _building_type;
}
int Building::GetHp () const
{
    return _hp;
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
void Building::Destroy (World & world) const
{
    if (_hp <= 0)
    {
        world.GetBuildings().erase(GetId());
        world.GetField()[_location->GetY()][_location->GetX()]->SetUnlock();
    }
}

Castle::Castle (World & world, int x, int y)
{
    _id = (int)world.GetBuildings().size() + 1;
    _hp = 1000;
    _max_hp = 1000;
    _building_type = 'a';
    _location = world.GetField()[y][x];
    _location->SetLock();
    world.GetBuildings().emplace(_id, this);
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
        if (i.second->GetCurCell()->GetNextCell()->GetNextCell() == nullptr)
        {
            TakeDamage(i.second->GetDamage());
            i.second->TakeDamage(i.second->GetHp());
            i.second->Die(world);
        }
    }
}

Tower::Tower (World & world, int x, int y)
{
    _id = (int)world.GetBuildings().size() + 1;
    _hp = 100;
    _max_hp = 100;
    _damage = 30;
    _reload = 2;
    _radius = 3;
    _building_type = 'b';
    _location = world.GetField()[y][x];
    _location->SetLock();
    world.GetBuildings().emplace(_id, this);
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
        int dist = ent.second->GetCurCell()->GetManhattanDistance(*_location);
        if (dist <= _radius)
        {
            _targets.emplace(dist + ent.second->GetHp(), ent.second);
        }
    }
}
void Tower::DealDamage ()
{
    if (!_targets.empty())
    {
        _targets.top().second->TakeDamage(_damage);
    }
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

Wall::Wall (World & world, int x, int y)
{
    _id = (int)world.GetBuildings().size() + 1;
    _hp = 200;
    _max_hp = 200;
    _building_type = 'c';
    _location = world.GetField()[y][x];
    _location->SetLock();
    world.GetBuildings().emplace(_id, this);
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

Spawner::Spawner (World & world, int x, int y)
{
    _id = (int)world.GetBuildings().size() + 1;
    _hp = 100;
    _max_hp = 100;
    _building_type = 'd';
    _count_troop = 1;
    _reload = 10;
    _location = world.GetField()[y][x];
//    _location->SetLock();
    world.GetBuildings().emplace(_id, this);
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
void Spawner::SpawnUnit (World & world, char unit_type)
{
    switch (unit_type)
    {
        case 'K':
        {
            auto K = new Knight(world, _location->GetX(), _location->GetY());
            _location->A_star(world, *world.GetField()[14][5]);
            break;
        }
        case 'J':
        {
            auto J = new Juggernaut(world, _location->GetX(), _location->GetY());
            break;
        }
        case 'A':
        {
            auto A = new Aviation(world, _location->GetX(), _location->GetY());
            break;
        }
        default:
        {
            break;
        }
    }
}

