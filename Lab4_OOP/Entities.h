#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H

class Warrior
{
protected:
    int _hp;
    double _velocity;
    int _damage;
    int _level;
public:
    Warrior();
    void Die();
    virtual int DealDamage() = 0;
    void TakeDamage (int damage);
    virtual int LevelUp () = 0;
};
class Knight : Warrior
{
public:
    void AvoidDamage();
    int LevelUp () override;
    int DealDamage() override;
};
class Juggernaut : Warrior
{
public:
    int LevelUp () override;
    int DealDamage() override;
};
class Aviation : Warrior
{
public:
    int LevelUp () override;
    int DealDamage() override;
};
class Hero : Warrior
{
private:
    int _radius_aura;
public:
    Hero();
    int LevelUp () override;
    int DealDamage() override;
};

#endif //LAB4_OOP_ENTITIES_H
