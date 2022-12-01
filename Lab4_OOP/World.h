#ifndef LAB4_OOP_WORLD_H
#define LAB4_OOP_WORLD_H
#include <map>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>
#include "Images.h"

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
    Cell* _go_to;
    Cell* _air_go_to;
    char _land_type;
public:
    Cell ();
    Cell (int x, int y);
    void SetLock ();
    void SetUnlock ();
    void SetAirLock ();
    void SetAirUnlock ();
    void SetWay (Cell & to);
    void SetLandType (std::string* map);
    [[nodiscard]] Cell* GetNextCell () const;
    [[nodiscard]] Cell* GetAirNextCell () const;
    [[nodiscard]] int GetX () const;
    [[nodiscard]] int GetY () const;
    [[nodiscard]] int GetManhattanDistance (Cell & target) const;
    std::vector <Cell*> GetNeighbors (World & world, std::vector <Cell*> & neighbors) const;
    [[nodiscard]] char GetLandType () const;
    void A_star (World & world, Cell & target);
};

class World
{
private:
    int _size_x;
    int _size_y;
    std::vector <std::vector <Cell*>> _field;
    std::map <int, Building*> _buildings;
    std::map <int, Warrior*> _entities;
public:
    World (int size_x, int size_y);
    [[nodiscard]] int GetSizeX () const;
    [[nodiscard]] int GetSizeY () const;
    std::vector <std::vector <Cell*>> & GetField ();
    std::map <int, Building*> & GetBuildings ();
    std::map <int, Warrior*> & GetEntities ();
    void ReadMap ();
    void DrawLand (sf::RenderWindow & window);
    void DrawBuildings (sf::RenderWindow & window);
    void DrawEntities (sf::RenderWindow & window);
};

#endif //LAB4_OOP_WORLD_H
