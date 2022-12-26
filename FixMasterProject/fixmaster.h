#ifndef FIXMASTER
#define FIXMASTER

#include <iostream>
#include <list>
#include <vector>

#include "master.h"
#include "salary.h"
#include "client.h"
#include "tools.h"
#include "fixorder.h"
#include "shiporder.h"
#include "annual.h"

using namespace std;

class UserInterface
{
private:
    MasterList* ptrMasterList;
    MasterInputScreen* ptrMasterInputScreen;
    SalaryRecord* ptrSalaryRecord;
    SalaryInputScreen* ptrSalaryInputScreen;
    ClientList* ptrClientList;
    ClientInputScreen* ptrClientInputScreen;
    SparePartList* ptrSparePartList; //todo
    SparePartInputScreen* ptrSparePartInputScreen; //todo
    ServiceList* ptrServiceList;
    ServiceInputScreen* ptrServiceInputScreen;
    FixOrderList* ptrFixOrderList;
    FixOrderInputScreen* ptrFixOrderInputScreen;
    ShipOrderList* ptrShipOrderList;
    ShipOrderInputScreen* ptrShipOrderInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;

public:
    UserInterface();
    ~UserInterface();
    void start();
};
#endif // FIXMASTER

