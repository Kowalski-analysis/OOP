#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H

class Warrior
{
private:
    int HP;
    double velocity;
    int damage;
    int level;
public:
    void DealDamage();
    void TakeDamage();
};
class Knight : Warrior
{
public:
    void AvoidDamage();
};
class Juggernaut : Warrior
{

};
class Aviation : Warrior
{

};
class Hero : Warrior
{

};

#endif //LAB4_OOP_ENTITIES_H
