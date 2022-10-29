#include "Entities.h"

int Warrior::DealDamage() const
{
    return damage;
}
void Warrior::TakeDamage(int damage)
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

void Knight::AvoidDamage()
{

}