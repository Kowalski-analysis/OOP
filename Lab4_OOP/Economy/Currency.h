#ifndef LAB4_OOP_CURRENCY_H
#define LAB4_OOP_CURRENCY_H

class Currency
{
private:
    int _count;
public:
    int GetCount ();
    void Increase ();
    bool BuyNewBuilding (int cost);
    void DrawBalance ();
};

#endif