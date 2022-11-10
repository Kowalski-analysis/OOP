#include "World.h"

Cell::Cell () : _x(0), _y(0), _lock(false), _distance()
{

}
Cell::Cell (int x, int y) : _x(x), _y(y), _lock(false)
{
    _distance = abs(x) + abs(y);
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
void Cell::SetDistance ()
{

}
void Cell::SetLock ()
{
    _lock = true;
}
void Cell::SetUnlock ()
{
    _lock = false;
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
int Cell::GetDistance () const
{
    return _distance;
}
int Cell::ManhattanDistance() const
{
    return abs(_x) + abs(_y);
}
std::vector <Cell*> Cell::GetNeighbors (World & world) const
{
    std::vector <Cell*> neighbors;
    for (int i = _x - 1; i <= _x + 1 ; i += 2)
    {
        for (int j = _y - 1; j <= _y + 1; j += 2)
        {
            if (!world._field[i][j]->_lock)
            {
                neighbors.push_back(world._field[i][j]);
            }
        }
    }
    return neighbors;
}
void Cell::A_star (World & world)
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
        if (current.second->_x == 0 && current.second->_y == 0)
        {
            break;
        }
        for (Cell* next : this->GetNeighbors(world))
        {
            int cost = cost_so_far[current.second];
            if (!cost_so_far.count(next) || cost < cost_so_far[next])
            {
                cost_so_far[next] = cost;
                int priority = cost + next->ManhattanDistance();
                frontier.emplace(priority, next);
                came_from[next] = current.second;
            }
        }
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
    _size = size;
    _field.reserve(2 * size + 1);
    for (int i = 0; i < 2 * size + 1; ++i)
    {
        _field[i].reserve(2 * size + 1);
    }
}
void World::DistanceUpdate ()
{

}
