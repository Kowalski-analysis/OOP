#include "Entities.h"
#include "Buildings.h"
#include "World.h"

Warrior::Warrior ()
{
    _hp = 100;
    _damage = 10;
    _level = 1;
    _velocity = 10.0;
    _cur_cell = nullptr;
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
void Warrior::Die ()
{
    if (_hp <= 0)
    {

    }
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

Hero::Hero ()
{
    _radius_aura = 5;
}
int Hero::LevelUp ()
{
    return 0;
}
