#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H
//#include "World.h"

class Warrior
{
protected:
    int hp;
    double velocity;
    int damage;
    int level;
public:
    void Die();
    virtual int DealDamage() = 0;
    void TakeDamage (int _damage);
    virtual int LevelUp () = 0;
};
class Knight : Warrior
{
public:
    void AvoidDamage();
    int LevelUp () override;
};
class Juggernaut : Warrior
{
public:
    int LevelUp () override;
};
class Aviation : Warrior
{
public:
    int LevelUp () override;
};
class Hero : Warrior
{
private:
    int radius_aura;
public:
    int LevelUp () override;
};

#endif //LAB4_OOP_ENTITIES_H
