#ifndef SHIPORDER
#define SHIPORDER

#include <iostream>
#include <list>
#include "tools.h"

using namespace std;

class ShipOrder
{
private:
    int ID;
    int day, month/*, count*/;
    string sparePartName;
    int sparePartPrice;

public:
    ShipOrder(int id, int dd, int mm, string spn, int spp);
    ~ShipOrder();
    int getID();
    int getDay();
    int getMonth();
    string getSparePartName();
    int getSparePartPrice();
    string getServiceName();
    int getServicePrice();
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
    void displayByID(int id);
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

