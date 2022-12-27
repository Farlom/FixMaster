#ifndef ANNUAL
#define ANNUAL

#include <iostream>
#include "tools.h"
#include "salary.h"

using namespace std;

class AnnualReport
{
private:
    SalaryRecord* ptrSR;
//    ExpenseRecord* ptrER;
//    FixOrderList* ptrFOL;
//    ShipOrderList* ptrSOL;
    SparePartList* ptrSPL;
    ServiceList* ptrSL;

    int totalSalaries;
    int totalSparePartsIn, totalSparePartsOut;
    int totalServices;
    int salaries;

public:
    AnnualReport(SalaryRecord*, SparePartList*, ServiceList*);
    void display();
    void updateTotalSalaries(int total);
};

#endif // ANNUAL

