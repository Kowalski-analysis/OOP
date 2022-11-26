#include "World.h"

std::string map_land[10] = {
        "1111111111",
        "1111111111",
        "1        1",
        "1        1",
        "1        1",
        "1        1",
        "1        1",
        "1        1",
        "1111111111",
        "1111111111",
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
void Cell::SetX (int x)
{
    _x = x;
}
void Cell::SetY (int y)
{
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
void Cell::SetLandType (std::string* map)
{
    _land_type = map[_y][_x];
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
std::vector <Cell*> Cell::GetNeighbors (World & world, std::vector <Cell*> & neighbors)
{
    for (int i = _x - 1; i <= _x + 1 ; i += 2)
    {
        for (int j = _y - 1; j <= _y + 1; j += 2)
        {
            if (!(world.GetField())[i][j]->_lock)
            {
                neighbors.push_back((world.GetField())[i][j]);
            }
        }
    }
    return neighbors;
}
char Cell::GetLandType () const
{
    return _land_type;
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

World::World (int size)
{
    _size = size + 2;
    std::vector <std::vector <Cell*>> new_vec(size + 2);
    _field = new_vec;
    for (int i = 0; i < size + 2; ++i)
    {
        std::vector <Cell*> vec(size + 2);
        _field[i] = vec;
    }
    for (int i = 0; i < size + 2; ++i) {
        for (int j = 0; j < size + 2; ++j) {
            Cell* new_cell = new Cell(i, j);
            if (i == 0 || j == 0 || i == size + 1 || j == size + 1)
            {
                new_cell->SetLock();
                new_cell->SetAirLock();
            }
            _field[i][j] = new_cell;
        }
    }
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
    sf::Image img;
    img.loadFromFile("../Textures/Land234.png");

    sf::Texture tex;
    tex.loadFromImage(img);

    sf::Sprite spt;
    spt.setTexture(tex);
    for (auto & i : _field)
    {
        for (auto & j : i)
        {
            float x = (float)j->GetX() * 180;
            float y = (float)j->GetY() * 46;
            if (j->GetY() % 2 == 1)
            {
                x += 90;
            }
            spt.setPosition(x, y);
            if (j->GetLandType() == '.')
            {
                continue;
            }
            if (j->GetLandType() == '1')
            {
                spt.setTextureRect(sf::IntRect(0,0,185,98));
            }
            if (j->GetLandType() == ' ')
            {
                spt.setTextureRect(sf::IntRect(185,0,185,98));
            }
            window.draw(spt);
        }
    }
}

///Ошибка в соседях и возможно в А*


