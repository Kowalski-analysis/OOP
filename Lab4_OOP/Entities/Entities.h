#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H
#include <ctime>
#include <iostream>

class Cell;
class Building;
class World;

class Warrior
{
protected:
    float _x;
    float _y;
    int _id;
    int _hp;
    double _velocity;
    int _damage;
    int _level;
    int _max_level;
    Cell* _cur_cell;
public:
    Warrior ();
    [[nodiscard]] float GetX () const;
    [[nodiscard]] float GetY () const;
    [[nodiscard]] int GetId () const;
    [[nodiscard]] int GetHp () const;
    [[nodiscard]] int GetDamage () const;
    Cell* GetCurCell ();
    void AddtoX (float x);
    void AddtoY (float y);
    void Die (World & world) const;
    void DealDamage (Building & building) const;
    void TakeDamage (int damage);
    void Move ();
    std::pair <float, float> DirectionOfNextCell ();
    virtual int LevelUp () = 0;
};
class Knight : public Warrior
{
public:
    Knight (World & world, int x, int y);
    static bool AvoidDamage ();
    int LevelUp () override;
};
class Juggernaut : public Warrior
{
public:
    Juggernaut (World & world, int x, int y);
    int LevelUp () override;
};
class Aviation : public Warrior
{
public:
    Aviation (World & world, int x, int y);
    int LevelUp () override;
};
class Hero : public Warrior
{
private:
    int _radius_aura;
public:
    Hero (World & world, int x, int y);
    int LevelUp () override;
};

#endif //LAB4_OOP_ENTITIES_H
