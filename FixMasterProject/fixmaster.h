#ifndef FIXMASTER
#define FIXMASTER

#include <iostream>
#include <list>
#include <vector>

using namespace std;

//чтобы брать приватные свойства класса
void getLine(string& inStr);
char getChar();

class Master {
private:
    string name;
    int salary;

public:
    Master(string n, int s);
    ~Master();
    string getName();
    int getSalary();
};

class MasterList {
private:
    list<Master*> setPtrsMasters;
    list<Master*>::iterator iter;
public:
    ~MasterList();
    void instertMaster(Master*);
    int getSal(string);
    bool display(); //вывод списка
    bool isEmpty();
    bool isExisting(string);
};

class MasterInputScreen {
private:
    MasterList* ptrMasterList;
    string mName;
    int mSalary;
public:
    MasterInputScreen(MasterList* ptrML):ptrMasterList(ptrML)
    {

    }
    void setMaster();
};



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

class Client //клиент сервиса
{
private:
    string name, autoName;

public:
    Client(string n, string an);
    ~Client();
    string getName();
    string getAutoName();
};

class ClientList
{
private:
    list<Client*> setPtrsClients;
    list<Client*>::iterator iter;

public:
    ~ClientList();
    void insertClient(Client*);
    bool display();
};

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


class FixOrder
{
private:
    //TODO

public:
    //TODO
};

class FixOrderList
{
private:
    //TODO

public:
    //TODO
};

class FixOrderInputScreen
{
private:
    //TODO
public:
    //TODO
};

class ShipOrder
{
private:
    //TODO
public:
   //TODO
};

class ShipOrderList
{
private:
   //TODO
public:
    //TODO
};

class ShipOrderInputScreen
{
private:
    //TODO

public:
    //TODO
};

class AnnualReport
{
private:
    //TODO

public:
    //TODO
};

class UserInterface
{
private:
    //TODO

public:
    //TODO
};

#endif // FIXMASTER

