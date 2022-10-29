#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H

class Warrior
{
private:
    int hp;
    double velocity;
    int damage;
    int level;
public:
    [[nodiscard]] int DealDamage() const;
    void TakeDamage(int damage);
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
