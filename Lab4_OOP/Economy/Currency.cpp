#include "Currency.h"

int Currency::GetCount ()
{
    return _count;
}
void Currency::Increase ()
{
    ++_count;
}
bool Currency::BuyNewBuilding (int cost)
{
    if (_count >= cost)
    {
        _count -= cost;
        return false;
    }
    return true;
}
void Currency::DrawBalance()
{

}