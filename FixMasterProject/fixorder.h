#ifndef FIXORDER
#define FIXORDER

#include <iostream>
#include <tools.h>
#include <client.h>
#include <master.h>
#include <salary.h>

using namespace std;

class FixOrder
{
private:
    int day, month;
    string autoName, clientName, masterName;

    SparePartList* ptrSparePart;
    int totalPrice;

public:
    FixOrder(int d, int m, string an, string cn, string mn);
    ~FixOrder();
    int getDay();
    int getMonth();
    string getAutoName();
    string getClientName();
    string getMasterName();
    void getSparePart();
    int getTotalPrice();
};

class FixOrderList
{
private:
    list<FixOrder*> setPtrsFixOrder;
    list<FixOrder*>::iterator iter;

public:
    ~FixOrderList();
    void insertSparePart(FixOrder*);
    bool display();
    bool display(string ownerN);
};

class FixOrderInputScreen
{
private:
    FixOrderList* ptrFixOrderList;

    ClientList* ptrClientList;
    ClientInputScreen* ptrClientInputScreen;

    MasterList* ptrMasterList;

    SalaryRecord* ptrSalaryRecord;
    SalaryInputScreen* ptrSalaryInputScreen;

    SparePartInputScreen* ptrSparePartInputScreen;
    SparePartList* ptrSparePartList; //+
    ServiceList* ptrServiceList; //+

    SparePartList* ptrSparePart;

    int day, month;
    string autoName, clientName, masterName, sparePartName;
    int sparePartPrice;

    int totalPrice;

public:
    FixOrderInputScreen(FixOrderList* ptrFO, ClientList* ptrCL, MasterList* ptrML, SalaryRecord* ptrSR, SparePartList* ptrSPL, ServiceList* ptrSL);
    void setFixOrder();
};

#endif // FIXORDER

