#ifndef LAB4_OOP_WORLD_H
#define LAB4_OOP_WORLD_H
#include <map>
#include <vector>
#include "Entities.h"
#include "Buildings.h"

class Cell
{
private:
    int x;
    int y;
    bool lock;
    double distance;
public:
    Cell();
    double Distance (Cell & Target);
    [[nodiscard]] double GetDistance() const;
    void SetLock();
    void SetUnlock();
};

class World
{
private:
    std::vector <std::vector <Cell>> field;
    std::map <int id, Building building> buildings;
    std::map <int id, Warrior warrior> entities;
public:
    World();
};
#endif //LAB4_OOP_WORLD_H
