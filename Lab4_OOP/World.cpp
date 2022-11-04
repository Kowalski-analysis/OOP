#include "World.h"

Cell::Cell () : _x(0), _y(0), _lock(false), _distance()
{
}
Cell::Cell (int x, int y, bool lock) : _x(x), _y(y), _lock(lock)
{
    _distance = abs(x) + abs(y);
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
void Cell::SetDistance ()
{

}
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

World::World (int size)
{
    _size = size;
    _field.reserve(size);
    for (int i = 0; i < size; ++i)
    {
        _field[i].reserve(size);
    }
}
void World::DistanceUpdate ()
{

}
