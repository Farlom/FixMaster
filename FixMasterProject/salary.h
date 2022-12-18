#ifndef SALARY
#define SALARY

#include <iostream>
#include <list>

#include <master.h>

using namespace std;

class SalaryRow {
private:
    string masterName;
    int salary[12];
public:
    SalaryRow(string);
    void setSalary(int);
    int getSumOfSalary();
    string getMasterName();
    int getSalaryFor(int);
};

class SalaryRecord
{
private:
    list <SalaryRow*> setPtrsSR;
    list <SalaryRow*>::iterator iter;

public:
    ~SalaryRecord();
    void insertSalary(string, int);
    void display();
    int getSumOfSalaries();

};

class SalaryInputScreen
{
private:
    MasterList* ptrMasterList;
    SalaryRecord* ptrSalaryRecord;

    string masterName;
    //float rentPaid;
    int month;

public:
    SalaryInputScreen(MasterList* ptrML, SalaryRecord* ptrSR): ptrMasterList(ptrML), ptrSalaryRecord(ptrSR)
    {

    }
    void setSalary();
};

#endif // SALARY

