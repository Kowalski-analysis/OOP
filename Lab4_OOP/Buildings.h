#ifndef LAB4_OOP_BUILDINGS_H
#define LAB4_OOP_BUILDINGS_H
#include <queue>

class Warrior;
class World;
class Cell;

class Building
{
protected:
    int _hp;
    int _max_hp;
    Cell* _location;
    int _level;
    int _level_max;
    char _building_type;
public:
    Building ();
    void Heal ();
    void TakeDamage (int damage);
    virtual int LevelUp () = 0;
    void Destroy ();
    void SetBuildingType ();
    Cell* GetCurrentCell ();
    [[nodiscard]] char GetBuildingType () const;
};
class Castle : public Building
{
public:
    Castle (World & world);
    int LevelUp () override;
    void CheckEntities (World & world);
};
class Tower : public Building
{
private:
    int _damage;
    int _radius;
    double _reload;
    std::priority_queue <std::pair <int, Warrior*>, std::vector <std::pair <int, Warrior*>>, std::greater<>> _targets;
public:
    Tower ();
    [[nodiscard]] int GetDamage () const;
    [[nodiscard]] int GetRadius () const;
    void FindTargets (World & world);
    void DealDamage (Warrior & warrior) const;
    int LevelUp () override;
};
class Wall : public Building
{
public:
    int LevelUp () override;
};
class Spawner : public Building
{
private:
    int _count_troop;
    double _reload;
public:
    Spawner ();
    int LevelUp () override;
};

#endif //LAB4_OOP_BUILDINGS_H
