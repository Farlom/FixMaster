#ifndef MASTER
#define MASTER

#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

class Master {
private:
    int ID;
    string name;
    int salary;

public:
    Master(int id, string n, int s);
    ~Master();
    int getID();
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
    string getNameByID(int);
//    void setID(Master*, )
    bool display(); //вывод списка
    bool isEmpty();
    bool isExisting(int);
    int length();
};

class MasterInputScreen {
private:
    MasterList* ptrMasterList;
    static int ID;
    string mName;
    int mSalary;
public:
    MasterInputScreen(MasterList* ptrML):ptrMasterList(ptrML)
    {

    }
    void setMaster();
};

#endif // MASTER

