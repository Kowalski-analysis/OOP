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
    sf::Sprite _sprite;
    char _land_type;
public:
    Cell ();
    Cell (int x, int y, char type);
    void SetX (int x);
    void SetY (int y);
    void SetLock ();
    void SetUnlock ();
    void SetWay (Cell & to);
    void SetSprite (char type);
    void SetLandType (std::string* map);
    [[nodiscard]] Cell* GetNextCell () const;
    [[nodiscard]] Cell* GetAirNextCell () const;
    [[nodiscard]] int GetX () const;
    [[nodiscard]] int GetY () const;
    [[nodiscard]] int GetManhattanDistance (Cell & target) const;
    std::vector <Cell*> GetNeighbors (World & world) const;
    [[nodiscard]] sf::Sprite GetSprite () const;
    [[nodiscard]] char GetLandType () const;
    void DrawSprite () const;
    void A_star (World & world, Cell & target);
};

class World
{
private:
    int _size;
    std::vector <std::vector <Cell*>> _field;
    sf::String _map_land;
    std::map <int, Building*> _buildings;
    std::map <int, Warrior*> _entities;
public:
    explicit World (int size);
    std::vector <std::vector <Cell*>> & GetField ();
    sf::String & GetMapLand ();
    std::map <int, Building*> & GetBuildings ();
    std::map <int, Warrior*> & GetEntities ();
    void ReadMap ();
    void DrawLand (sf::RenderWindow & window);
};

#endif //LAB4_OOP_WORLD_H
