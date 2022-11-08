#ifndef LAB4_OOP_WORLD_H
#define LAB4_OOP_WORLD_H
#include <map>
#include <vector>
#include <queue>

class Warrior;
class Building;

class Cell
{
private:
    int _x;
    int _y;
    bool _lock;
    int _distance;
    int _id;
    Cell* _go_to;
public:
    Cell ();
    Cell (int x, int y, bool lock);
    void SetX (int x);
    void SetY (int y);
    void SetDistance ();
    void SetLock ();
    void SetUnlock ();
    [[nodiscard]] int GetX () const;
    [[nodiscard]] int GetY () const;
    [[nodiscard]] int GetDistance () const;
    [[nodiscard]] int ManhattanDistance () const;
    void A_star ();
};

class World
{
private:
    int _size;
    std::vector <std::vector <Cell>> _field;
    std::map <int, Building*> _buildings;
    std::map <int, Warrior*> _entities;
public:
    explicit World (int size);
    void DistanceUpdate ();
};

#endif //LAB4_OOP_WORLD_H
