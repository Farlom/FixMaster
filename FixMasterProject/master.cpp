#include "master.h"

using namespace std;

Master::Master(int id, string n, int s): ID(id), name(n), salary(s)
{
    //rdy
}

Master::~Master()
{
    //rdy
}

string Master::getName()
{
    return name;
}

int Master::getSalary()
{
    return salary;
}

int Master::getID()
{
    return ID;
}

//методы класса MasterList
MasterList::~MasterList()
{
    //удаляем указатели из контейнера
    while (!setPtrsMasters.empty())
    {
        iter = setPtrsMasters.begin();
        delete *iter;
        setPtrsMasters.erase(iter);
    }
}

void MasterList::instertMaster(Master* ptrM)
{
    //вставить в конец list`а
    setPtrsMasters.push_back(ptrM);
}

int MasterList::getSal(string mName)
{
    int sal;
    iter = setPtrsMasters.begin();
    while (iter != setPtrsMasters.end())
    {
        sal = (*iter)->getSalary();
        if (mName == ((*iter)->getName()))
        {
            return sal;
        }
        iter++;
    }
    //не нашел = -1
    return -1;
}

string MasterList::getNameByID(int id)
{
    iter = setPtrsMasters.begin();
    while (iter != setPtrsMasters.end())
    {
        if((*iter)->getID() == id)
        {
            return (*iter)->getName();
        }
        *iter++;
    }
    return "Not found.";
}

bool MasterList::display()
{
    wcout << L"Список мастеров: \n";
    if (setPtrsMasters.empty())
    {
       wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
       getch();
       system("cls");
       return false;
    }
    else
    {
        wcout << L"ID\tИмя\tОклад\n";
        iter = setPtrsMasters.begin();
        while (iter != setPtrsMasters.end())
        {
            cout << (*iter)->getID() << "\t" << (*iter)->getName() << "\t" << (*iter)->getSalary() << "\n";
            *iter++;
        }
        getch();
        return true;
    }
}

bool MasterList::isEmpty()
{
    return setPtrsMasters.empty();
}

bool MasterList::isExisting(int id)
{
    iter = setPtrsMasters.begin();
    while(iter != setPtrsMasters.end())
    {
        if((*iter)->getID() == id)
            return true;
        else *iter++;
    }
    return false;
}

int MasterList::length()
{
    return setPtrsMasters.size();
}

//cвойства и методы класса MasterInputScreen

int MasterInputScreen::ID = 1;

void MasterInputScreen::setMaster()
{
    wcout << L"Введите имя мастера: ";
    cin >> mName;
    wcout << L"Введите оплату: ";
    cin >> mSalary;

    Master* ptrMaster = new Master(ID, mName, mSalary);
    ptrMasterList->instertMaster(ptrMaster);
    ID++;
}
