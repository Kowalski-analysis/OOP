#include "World.h"
#include "../Buildings/Buildings.h"
#include "../Entities/Entities.h"

std::string map_land[22] = {
        "hhhhaahhhh",
        "hbbbbbbbbh",
        "honoabbbch",
        "homoccccch",
        "hojoffffch",
        "oioiiaaaah",
        "hcceeeecch",
        "hcccccccch",
        "hdddggdddh",
        "hhheeeehhh",
        "hhhhaahhhh",
        "hbbbbbbbbh",
        "honoabbbch",
        "homoccccch",
        "hojoffffch",
        "oioiiaaaah",
        "hcceeeecch",
        "hcccccccch",
        "hdddggdddh",
        "hhheeeehhh",
        "hojoffffch",
        "oioiiaaaah",
};

Cell::Cell () : _x(0), _y(0), _lock(false), _air_lock(false)
{
    _go_to = nullptr;
    _air_go_to = nullptr;
    _land_type = ' ';
}
Cell::Cell (int x, int y) : Cell()
{
    _x = x;
    _y = y;
}
void Cell::SetLock ()
{
    _lock = true;
}
void Cell::SetUnlock ()
{
    _lock = false;
}
void Cell::SetAirLock ()
{
    _air_lock = true;
}
void Cell::SetAirUnlock ()
{
    _air_lock = false;
}
void Cell::SetWay (Cell & to)
{
    _go_to = &to;
}
void Cell::SetAirWay (Cell & to)
{
    _air_go_to = &to;
}
void Cell::SetLandType (std::string* map)
{
    _land_type = map[_y][_x];
    if ((int)map[_y][_x] / 105 == 1)
    {
        SetLock();
    }
}
int Cell::GetX () const
{
    return _x;
}
int Cell::GetY () const
{
    return _y;
}
Cell* Cell::GetNextCell () const
{
    return _go_to;
}
Cell* Cell::GetAirNextCell () const
{
    return _air_go_to;
}
int Cell::GetManhattanDistance (Cell & target) const
{
    return abs(_x - target.GetX()) + abs(_y - target.GetY());
}
std::vector <Cell*> Cell::GetNeighbors (World & world, std::vector <Cell*> & neighbors) const
{
    for (int i = _x - 1; i <= _x + 1; i += 2)
    {
        if (i < 0 || i >= world.GetSizeX())
        {
            continue;
        }
        if (!(world.GetField())[_y][i]->_lock)
        {
            neighbors.push_back((world.GetField())[_y][i]);
        }
    }
    for (int i = _y - 1; i <= _y + 1; i += 2)
    {
        if (i < 0 || i >= world.GetSizeY())
        {
            continue;
        }
        if (!(world.GetField())[i][_x]->_lock)
        {
            neighbors.push_back((world.GetField())[i][_x]);
        }
    }
    return neighbors;
}
char Cell::GetLandType () const
{
    return _land_type;
}
bool Cell::GetLock () const
{
    return _lock;
}
bool Cell::GetAirLock () const
{
    return _air_lock;
}
void Cell::A_star (World & world, Cell & target)
{
    std::priority_queue <std::pair <int, Cell*>, std::vector <std::pair <int, Cell*>>, std::greater<>> frontier;
    std::map <Cell*, Cell*> came_from;
    std::map <Cell*, int> cost_so_far;
    frontier.push(std::make_pair(0, this));
    came_from[this] = this;
    cost_so_far[this] = 0;
    while (!frontier.empty())
    {
        std::pair current = frontier.top();
        frontier.pop();
        if (current.second == &target)
        {
            break;
        }
        std::vector <Cell*> neighbors;
        for (Cell* next : current.second->GetNeighbors(world, neighbors))
        {
            int cost = cost_so_far[current.second];
            if (!cost_so_far.count(next) || cost < cost_so_far[next])
            {
                cost_so_far[next] = cost;
                int priority = cost + next->GetManhattanDistance(target);
                frontier.emplace(priority, next);
                came_from[next] = current.second;
            }
        }
    }
    Cell* to = &target;
    Cell* from = came_from[&target];
    while (to != this)
    {
    from->SetWay(*to);
    to = from;
    from = came_from[from];
    }
}

World::World (int size_x, int size_y)
{
    _size_x = size_x + 2;
    _size_y = size_y + 2;
    _entities.clear();
    _buildings.clear();
    std::vector <std::vector <Cell*>> new_vec(_size_y);
    _field = new_vec;
    for (int i = 0; i < _size_y; ++i)
    {
        std::vector <Cell*> vec(_size_x);
        _field[i] = vec;
    }
    for (int i = 0; i < _size_y; ++i) {
        for (int j = 0; j < _size_x; ++j) {
            Cell* new_cell = new Cell(j, i);
            if (i == 0 || j == 0 || i == _size_y - 1 || j == _size_x - 1)
            {
                new_cell->SetLock();
                new_cell->SetAirLock();
            }
            _field[i][j] = new_cell;
        }
    }
}
int World::GetSizeX () const
{
    return _size_x;
}
int World::GetSizeY () const
{
    return _size_y;
}
std::vector <std::vector <Cell*>> & World::GetField ()
{
    return _field;
}
std::map <int, Building*> & World::GetBuildings ()
{
    return _buildings;
}
std::map <int, Warrior*> & World::GetEntities ()
{
    return _entities;
}
void World::ReadMap ()
{
    for (auto & i : _field)
    {
        for (auto & j : i)
        {
            j->SetLandType(map_land);
        }
    }
}
void World::DrawLand (sf::RenderWindow & window)
{
    ReadMap();
    sf::Image img;
    img.loadFromFile("../Textures/Land.png");

    sf::Texture tex;
    tex.loadFromImage(img);

    sf::Sprite spt;
    spt.setTexture(tex);
    for (auto & i : _field)
    {
        for (auto & j : i)
        {
            if (j->GetLandType() == ' ')
            {
                continue;
            }
            float x = (float)j->GetX() * 176;
            float y = (float)j->GetY() * 44;
            if (j->GetY() % 2 == 1)
            {
                x += 88;
            }
            spt.setPosition(x, y);
            int x0 = ((int)j->GetLandType() - 97) * 180 % 1440;
            int y0 = ((int)j->GetLandType() / 105) * 92;
            int x1 = 180;
            int y1 = 92;
            spt.setTextureRect(sf::IntRect(x0,y0,x1,y1));
            window.draw(spt);
        }
    }
}
void World::DrawBuildings (sf::RenderWindow & window)
{
    sf::Image img;
    img.loadFromFile("../Textures/Buildings_test.png");

    sf::Texture tex;
    tex.loadFromImage(img);

    sf::Sprite spt;
    spt.setTexture(tex);
    for (auto i : _buildings)
    {
        float x = (float)i.second->GetCurCell()->GetX() * 176;
        float y = (float)i.second->GetCurCell()->GetY() * 44 - 354;
        if (i.second->GetCurCell()->GetY() % 2 == 1)
        {
            x += 88;
        }
        spt.setPosition(x, y);
        int x0 = ((int)i.second->GetBuildingType() - 97) * 180;
        int y0 = ((int)i.second->GetBuildingType() / 105) * 446;
        int x1 = 180;
        int y1 = 446;
        spt.setTextureRect(sf::IntRect(x0,y0,x1,y1));
        window.draw(spt);
    }
}
void World::DrawEntities (sf::RenderWindow &window, float time)
{
    sf::Image img;
    img.loadFromFile("../Textures/Entities_test.png");

    sf::Texture tex;
    tex.loadFromImage(img);

    sf::Sprite spt;
    spt.setTexture(tex);
    spt.setTextureRect(sf::IntRect(0,0,50,50));

}

