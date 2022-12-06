#ifndef FIXMASTER
#define FIXMASTER

#include <iostream>
#include <list>

using namespace std;

class Master {
private:
    string name;
    int salary;
    //int ID;
public:
    Master(string n, int s);
    ~Master();
    string getName();
    int getSalary();
};

class MasterList {
private:
    list <Master*> setPtrsMasters;
    list <Master*>::iterator iter;
public:
    ~MasterList();
    void instertMaster(Master*);
    int getSal(string);
    void display(); //вывод списка
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

#endif // FIXMASTER

