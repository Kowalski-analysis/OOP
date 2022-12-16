#include "Entities.h"
#include "../Buildings/Buildings.h"
#include "../World/World.h"

Warrior::Warrior ()
{
    _x = 0;
    _y = 0;
    _id = 0;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = nullptr;
}
float Warrior::GetX () const
{
    return _x;
}
float Warrior::GetY () const
{
    return _y;
}
int Warrior::GetId() const
{
    return _id;
}
int Warrior::GetHp () const
{
    return _hp;
}
int Warrior::GetDamage () const
{
    return _damage;
}
Cell* Warrior::GetCurCell ()
{
    return _cur_cell;
}
void Warrior::AddtoX (float x)
{
    _x += x;
}
void Warrior::AddtoY (float y)
{
    _y += y;
}
void Warrior::Die (World & world) const
{
    world.GetEntities().erase(GetId());
}
void Warrior::DealDamage (Building & building) const
{
    building.TakeDamage(_damage);
}
void Warrior::TakeDamage (int damage)
{
    if (this->_hp <= damage)
    {
        this->_hp = 0;
    }
    else
    {
        this->_hp -= damage;
    }
}
void Warrior::Move (World & world)
{
    if (_cur_cell->GetNextCell()->GetNextCell() == nullptr)
    {
        Die(world);
        return;
    }
    _cur_cell = _cur_cell->GetNextCell();
}
std::pair <float, float> Warrior::DirectionOfNextCell ()
{
    auto x = (float)(_cur_cell->GetNextCell()->GetX() - _cur_cell->GetX());
    auto y = (float)(_cur_cell->GetNextCell()->GetY() - _cur_cell->GetY());
    if (_cur_cell->GetNextCell()->GetY() % 2 == 1 && y == 1)
    {
        x += 0.5f;
    }
    if (_cur_cell->GetNextCell()->GetY() % 2 == 0 && y == 1)
    {
        x -= 0.5f;
    }
    return std::make_pair(x, y);
}

Knight::Knight (World & world, int x, int y)
{
    _id = (int)world.GetEntities().size() + 1;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = world.GetField()[y][x];
    _x = (float)_cur_cell->GetX() * 176;
    if (_cur_cell->GetX() % 2 == 1)
    {
        _x += 88;
    }
    _y = (float)_cur_cell->GetY() * 44;
    world.GetEntities().emplace(_id, this);
}
bool Knight::AvoidDamage ()
{
    srand(time(nullptr));
    int a = rand() % 100;
    return a >= 75;
}
int Knight::LevelUp ()
{
    if (_level == _max_level)
    {
        return 1;
    }
    ++_level;
    _damage += 10;
    _hp += 100;
    return 0;
}

Juggernaut::Juggernaut (World & world, int x, int y)
{
    _id = (int)world.GetEntities().size() + 1;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = world.GetField()[y][x];
    _x = (float)_cur_cell->GetX() * 176;
    if (_cur_cell->GetX() % 2 == 1)
    {
        _x += 88;
    }
    _y = (float)_cur_cell->GetY() * 44;
    world.GetEntities().emplace(_id, this);
}
int Juggernaut::LevelUp ()
{
    if (_level == _max_level)
    {
        return 1;
    }
    ++_level;
    _damage += 20;
    _hp += 200;
    return 0;
}

Aviation::Aviation (World & world, int x, int y)
{
    _id = (int)world.GetEntities().size() + 1;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = world.GetField()[y][x];
    _x = (float)_cur_cell->GetX() * 176;
    if (_cur_cell->GetX() % 2 == 1)
    {
        _x += 88;
    }
    _y = (float)_cur_cell->GetY() * 44;
    world.GetEntities().emplace(_id, this);
}
int Aviation::LevelUp ()
{
    if (_level == _max_level)
    {
        return 1;
    }
    ++_level;
    _damage += 30;
    return 0;
}

Hero::Hero (World & world, int x, int y)
{
    _id = (int)world.GetEntities().size() + 1;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = world.GetField()[y][x];
    _x = (float)_cur_cell->GetX() * 176;
    if (_cur_cell->GetX() % 2 == 1)
    {
        _x += 88;
    }
    _y = (float)_cur_cell->GetY() * 44;
    world.GetEntities().emplace(_id, this);
    _radius_aura = 5;
}
int Hero::LevelUp ()
{
    if (_level == _max_level)
    {
        return 1;
    }
    ++_level;
    _radius_aura += 1;
    return 0;
}
