#ifndef LAB4_OOP_WORLD_H
#define LAB4_OOP_WORLD_H
#include <map>
#include <vector>
#include <queue>

class Warrior;
class Building;
class World;
class Tower;

class Cell
{
private:
    int _x;
    int _y;
    bool _lock;
    bool _air_lock;
//    int _id;
    Cell* _go_to;
    Cell* _air_go_to;
public:
    Cell ();
    Cell (int x, int y);
    void SetX (int x);
    void SetY (int y);
    void SetLock ();
    void SetUnlock ();
    void SetWay (Cell & to);
//    [[nodiscard]] int GetId () const;
    [[nodiscard]] Cell* GetNextCell () const;
    [[nodiscard]] Cell* GetAirNextCell () const;
    [[nodiscard]] int GetX () const;
    [[nodiscard]] int GetY () const;
    [[nodiscard]] int ManhattanDistance (Cell & target) const;
    std::vector <Cell*> GetNeighbors (World & world) const;
    void A_star (World & world, Cell & target);
};

class World
{
private:
    int _size;
    std::vector <std::vector <Cell*>> _field;
    std::map <int, Building*> _buildings;
    std::map <int, Warrior*> _entities;
public:
    explicit World (int size);
    std::vector <std::vector <Cell*>> GetField ();
    std::map <int, Building*> GetBuildings ();
    std::map <int, Warrior*> GetEntities ();
    void DistanceUpdate ();
};

#endif //LAB4_OOP_WORLD_H
