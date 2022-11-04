#include "Entities.h"

Warrior::Warrior ()
{
    _hp = 100;
    _damage = 10;
    _level = 1;
    _velocity = 10.0;
}
int Warrior::DealDamage ()
{
    return _damage;
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
void Warrior::Die ()
{
    if (_hp <= 0)
    {

    }
}

void Knight::AvoidDamage ()
{

}
int Knight::LevelUp ()
{
    return 0;
}
int Knight::DealDamage ()
{
    return 0;
}

int Juggernaut::LevelUp ()
{
    return 0;
}
int Juggernaut::DealDamage ()
{
    return 0;
}

int Aviation::LevelUp ()
{
    return 0;
}
int Aviation::DealDamage ()
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
int Hero::DealDamage ()
{
    return 0;
}
