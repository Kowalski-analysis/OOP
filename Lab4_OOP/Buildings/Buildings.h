#ifndef LAB4_OOP_BUILDINGS_H
#define LAB4_OOP_BUILDINGS_H
#include <queue>

class Warrior;
class World;
class Cell;

class Building
{
protected:
    int _id;
    int _hp;
    int _max_hp;
    Cell* _location;
    int _level;
    int _level_max;
    char _building_type;
public:
    Building ();
    [[nodiscard]] int GetId () const ;
    Cell* GetCurCell ();
    [[nodiscard]] char GetBuildingType () const;
    [[nodiscard]] int GetHp () const;
    void Heal ();
    void TakeDamage (int damage);
    virtual int LevelUp () = 0;
    void Destroy (World &world) const;
};
class Castle : public Building
{
public:
    Castle (World &world, int x, int y);
    int LevelUp () override;
    void CheckEntities (World &world);
};
class Tower : public Building
{
private:
    int _damage;
    int _radius;
    double _reload;
    std::priority_queue <std::pair <int, Warrior*>, std::vector
    <std::pair <int, Warrior*>>, std::greater<>> _targets;
public:
    Tower (World & world, int x, int y);
    [[nodiscard]] int GetDamage () const;
    [[nodiscard]] int GetRadius () const;

    void FindTargets (World & world);
    void DealDamage ();
    int LevelUp () override;
};
class Wall : public Building
{
public:
    Wall (World & world, int x, int y);
    int LevelUp () override;
};
class Spawner : public Building
{
private:
    int _count_troop;
    double _reload;
public:
    Spawner (World & world, int x, int y);
    void SpawnUnit (World &world, char unit_type);
    int LevelUp () override;
};

#endif //LAB4_OOP_BUILDINGS_H
