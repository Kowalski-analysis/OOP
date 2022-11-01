#include "Entities.h"

int Warrior::DealDamage() const
{
    return damage;
}
void Warrior::TakeDamage(int _damage)
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
void Warrior::Die()
{
    if (hp <= 0)
    {

    }
}

void Knight::AvoidDamage()
{

}