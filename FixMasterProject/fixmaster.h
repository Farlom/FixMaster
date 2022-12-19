#ifndef FIXMASTER
#define FIXMASTER

#include <iostream>
#include <list>
#include <vector>

#include <master.h>
#include <salary.h>
#include <client.h>
#include <tools.h>
#include <fixorder.h>
#include <shiporder.h>
#include <annual.h>

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
    SparePartInputScreen* ptrSparePartInputScreen;
    SparePartList* ptrSparePartList;

    char ch;

public:
    UserInterface();
    ~UserInterface();
    void start();
};

#endif // FIXMASTER

