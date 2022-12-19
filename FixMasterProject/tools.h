#ifndef TOOLS
#define TOOLS

#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

class SparePart //з\ч
{
private:
    string name, ownerName;
    int price, month;

public:
    SparePart(string n, string on, int p, int m);
    ~SparePart();
    string getName();
    string getOwnerName();
    int getPrice();
    int getMonth();
//    void setClient(string);
};

class SparePartList
{
private:
    list<SparePart*> setPtrsSpareParts;
    list<SparePart*>::iterator iter;

public:
    ~SparePartList();
    void insertSparePart(SparePart*);
    void display(string on, int m);
    void display();
};

class SparePartInputScreen
{
private:
    SparePartList* ptrSparePartList;
    string sparePartName, ownerName;
    int price, month;
    SparePart* ptrSparePart;

public:
    SparePartInputScreen(SparePartList* ptrSPL): ptrSparePartList(ptrSPL)
    {

    }

    void setSparePart(int, string);
//    SparePart* getPtr();
//    void setClient(SparePart*, string);
};

class Service //услуга
{
private:
    string name, ownerName;
    int price, month;

public:
    Service(string n, string on, int p, int m);
    ~Service();
    string getOwnerName();
    string getName();
    int getPrice();
    int getMonth();
};

class ServiceList
{
private:
    list<Service*> setPtrsServices;
    list<Service*>::iterator iter;

public:
    ~ServiceList();
    void insertService(Service*);
    void display();
    void display(string on, int m);
};

class ServiceInputScreen
{
private:
    ServiceList* ptrServiceList;
    string serviceName, ownerName;
    int price, month;

public:
    ServiceInputScreen(ServiceList* ptrSL): ptrServiceList(ptrSL)
    {

    }

    void setService(int, string);
};

#endif // TOOLS

