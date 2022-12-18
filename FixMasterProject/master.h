#ifndef MASTER
#define MASTER

#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

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

#endif // MASTER

