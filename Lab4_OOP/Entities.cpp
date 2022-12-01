#include "Entities.h"
#include "Buildings.h"
#include "World.h"

Warrior::Warrior ()
{
    _id = 0;
    _hp = 100;
    _damage = 10;
    _level = 1;
    _max_level = 5;
    _velocity = 1;
    _cur_cell = nullptr;
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
void Warrior::Move ()
{
    _cur_cell = _cur_cell->GetNextCell();
}
std::pair <int, int> Warrior::DirectionOfNextCell ()
{
    int x = _cur_cell->GetNextCell()->GetX() - _cur_cell->GetX();
    int y = _cur_cell->GetNextCell()->GetY() - _cur_cell->GetY();
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
    return 0;
}

int Juggernaut::LevelUp ()
{
    return 0;
}

int Aviation::LevelUp ()
{
    return 0;
}

int Hero::LevelUp ()
{
    return 0;
}
