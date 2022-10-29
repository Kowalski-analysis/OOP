#include "World.h"

Cell::Cell() : x(0), y(0), lock(false), distance(0)
{}
double Cell::Distance(Cell &Target)
{

}
double Cell::GetDistance() const
{
    return distance;
}
void Cell::SetLock()
{
    lock = true;
}
void Cell::SetUnlock()
{
    lock = false;
}

World::World()
{

}