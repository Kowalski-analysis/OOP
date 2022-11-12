#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H
#include <ctime>
#include <iostream>

class Cell;
class Building;

class Warrior
{
protected:
    int _hp;
    double _velocity;
    int _damage;
    int _level;
    Cell* _next_cell;
public:
    Warrior ();
    [[nodiscard]] int GetHp () const;
    [[nodiscard]] int GetDamage () const;
    Cell* GetNextCell ();
    void Die ();
    void DealDamage (Building & building) const;
    void TakeDamage (int damage);
    virtual int LevelUp () = 0;
};
class Knight : Warrior
{
public:
    static int AvoidDamage ();
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
    int _radius_aura;
public:
    Hero();
    int LevelUp () override;
};

#endif //LAB4_OOP_ENTITIES_H
