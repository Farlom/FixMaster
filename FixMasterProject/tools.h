#ifndef TOOLS
#define TOOLS

#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

class SparePart //з\ч
{
private:
    int ID;
    string name, ownerName;
    int price, day, month;


public:
    SparePart(int id, string n, string on, int p, int dd, int mm);
    ~SparePart();
    string getName();
    string getOwnerName();
//    void setID(int);
    int getID();
    int getPrice();
    int getDay();
    int getMonth();
    void setClient(string);
};

class SparePartList
{
private:
    list<SparePart*> setPtrsSpareParts;
    list<SparePart*>::iterator iter;

public:
    ~SparePartList();
    void insertSparePart(SparePart*);
    void setID(SparePart*, int);
    void display(string on, int m);
    void display(); //вывод всего списка
    void display(int mm, int dd); //вывод списка запчастей, заказанных до dd, mm, ownerName = 0;
    void displayByID(int id);
    SparePart* getPtrByID(int id);
    bool isEmpty();
    bool isExisting(int id);
    bool isFree(int id);
    void updateSparePart(int id, string cn);
    int length();

    string getName(int id);
    int getPrice(int id);

    int getTotalPrice(bool free);
};

class SparePartInputScreen
{
private:
    SparePartList* ptrSparePartList;
    int ID;
    string sparePartName, ownerName;
    int day, month;
    int price;
    SparePart* ptrSparePart;

public:
    SparePartInputScreen(SparePartList* ptrSPL): ptrSparePartList(ptrSPL)
    {

    }

    void setSparePart(int, int, string);
    string getSparePartName();
    int getSparePartPrice();
//    SparePart* getPtr();
//    void setClient(SparePart*, string);
};

class Service //услуга
{
private:
    string name, ownerName;
    int price, day, month;

public:
    Service(string n, string on, int p, int d, int m);
    ~Service();
    string getOwnerName();
    string getName();
    int getDay();
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
    int getTotalServices();
};

class ServiceInputScreen
{
private:
    ServiceList* ptrServiceList;
    string serviceName, ownerName;
    int price, day, month;

public:
    ServiceInputScreen(ServiceList* ptrSL): ptrServiceList(ptrSL)
    {

    }

    void setService(int, int, string);
    string getName();
    int getPrice();
};

#endif // TOOLS

