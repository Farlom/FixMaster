#ifndef SHIPORDER
#define SHIPORDER

#include <iostream>
#include <list>
#include <tools.h>

using namespace std;

class ShipOrder
{
private:
    int day, month/*, count*/;
    string sparePartName;
    int sparePartPrice;

public:
    ShipOrder(int dd, int mm, string spn, int spp);
    ~ShipOrder();
    int getDay();
    int getMonth();
    string getSparePartName();
    int getSparePartPrice();
};

class ShipOrderList
{
private:
    list<ShipOrder*> setPtrsShipOrder;
    list<ShipOrder*>::iterator iter;

public:
    ~ShipOrderList();
    void insert(ShipOrder*);
    int getTotalPrice();
    void display();
};

class ShipOrderInputScreen
{
private:
    ShipOrderList* ptrShipOrderList;
    SparePartList* ptrSparePartList;
    SparePartInputScreen* ptrSparePartInputScreen;
    int day, month;
    string sparePartName;
    int sparePartPrice;

public:
    ShipOrderInputScreen(ShipOrderList* ptrSOL, SparePartList* ptrSPL);
    void setShipOrder();
};

#endif // SHIPORDER

