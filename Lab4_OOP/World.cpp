#include "World.h"

Cell::Cell () : _x(0), _y(0), _lock(false)
{
    _go_to = nullptr;
}
Cell::Cell (int x, int y) : _x(x), _y(y), _lock(false)
{
    _go_to = nullptr;
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

//int Cell::GetId() const
//{
//    return _id;
//}

int Cell::GetX () const
{
    return _x;
}
int Cell::GetY () const
{
    return _y;
}
int Cell::ManhattanDistance (Cell & target) const
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
                int priority = cost + next->ManhattanDistance(target);
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

//World::World (int size)
//{
//    _size = size;
//    int x = -size, y = -size;
//    for (int i = 0; i < (size + 1) * (size + 1); ++i, ++x)
//    {
//        if (i == size)
//        {
//            x = -size;
//            ++y;
//        }
//        Cell new_cell(x, y, i);
//        _field.emplace(new_cell.GetId(), &new_cell);
//    }
//}

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
            Cell new_cell(i, j);
            if (i == 0 || j == 0 || i == size + 1 || j == size + 1)
            {
                new_cell.SetLock();
            }
            _field[i][j] = &new_cell;
        }
    }
}
std::vector <std::vector <Cell*>> World::GetField ()
{
    return _field;
}
std::map <int, Building*> World::GetBuildings ()
{
    return _buildings;
}
std::map <int, Warrior*> World::GetEntities ()
{
    return _entities;
}
void World::DistanceUpdate ()
{

}
