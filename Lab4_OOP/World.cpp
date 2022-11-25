#include "World.h"

std::string map_land[21] = {
        "111111111111111111111",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "1                   1",
        "                    1",
        "111111111111111111111",
};


Cell::Cell () : _x(0), _y(0), _lock(false), _air_lock(false)
{
    _go_to = nullptr;
    _air_go_to = nullptr;
    _land_type = ' ';
    sf::Image img;
    img.loadFromFile("../Textures/Land234.png");
    sf::Texture tex;
    tex.loadFromImage(img);
    sf::Sprite spt;
    spt.setTexture(tex);
    _sprite = std::move(spt);
    _sprite.setTextureRect(sf::IntRect (0, 0, 50, 50));
}
Cell::Cell (int x, int y, char type) : Cell()
{
    _x = x;
    _y = y;
    SetSprite (type);
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
void Cell::SetWay (Cell & to)
{
    _go_to = &to;
}
void Cell::SetSprite (char type)
{
    switch (type)
    {
        case '1' :
        {
            _sprite.setTextureRect(sf::IntRect(0,0,185,98));
        }

        case ' ' :
        {
            _sprite.setTextureRect(sf::IntRect(185,0,185,98));
        }
        default:
        {

        }
    }
    _sprite.setPosition((float)_x * 180 + (float)(_x % 2 * 90), (float)_y * 92);
}
void Cell::SetLandType (std::string* map)
{
    _land_type = map[_x][_y];
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
std::vector <Cell*> Cell::GetNeighbors (World & world) const
{
    std::vector <Cell*> neighbors;
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
sf::Sprite Cell::GetSprite () const
{
    return _sprite;
}
char Cell::GetLandType () const
{
    return _land_type;
}
void Cell::DrawSprite () const
{

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
        for (Cell* next : current.second->GetNeighbors(world))
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
    _field.reserve(size + 2);
    for (int i = 0; i < size + 2; ++i)
    {
        _field[i].reserve( size + 2);
    }
    for (int i = 0; i < size + 2; ++i) {
        for (int j = 0; j < size + 2; ++j) {
            Cell new_cell(i, j, ' ');
            if (i == 0 || j == 0 || i == size + 1 || j == size + 1)
            {
                new_cell.SetLock();
            }
            _field[i][j] = &new_cell;
        }
    }

}
std::vector <std::vector <Cell*>> & World::GetField ()
{
    return _field;
}
sf::String & World::GetMapLand ()
{
    return _map_land;
}
std::map <int, Building*> & World::GetBuildings ()
{
    return _buildings;
}
std::map <int, Warrior*> & World::GetEntities ()
{
    return _entities;
}
void World::ReadMap()
{
    for (auto & i : _field)
    {
        for (auto & j : i)
        {
            j->SetLandType(map_land);
            j->SetSprite(j->GetLandType());
        }
    }
}
void World::DrawLand (sf::RenderWindow & window)
{
    for (auto & i : _field)
    {
        for (auto & j : i)
        {
            window.draw(j->GetSprite());
        }
    }
}





