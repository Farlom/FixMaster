#include <iostream>
#include <conio.h> //getch();
#include "fixmaster.h"

//методы класса Master
Master::Master(string n, int s): name(n), salary(s)
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
        wcout << L"Имя\tОклад\n";
        iter = setPtrsMasters.begin();
        while (iter != setPtrsMasters.end())
        {
            cout << (*iter)->getName() << "\t" << (*iter)->getSalary() << "\n";
            *iter++;
        }
        return true;
    }
}

bool MasterList::isEmpty()
{
    return setPtrsMasters.empty();
}

bool MasterList::isExisting(string name)
{
    iter = setPtrsMasters.begin();
    while(iter != setPtrsMasters.end())
    {
        if((*iter)->getName() == name)
            return true;
        else *iter++;
    }
    return false;
}

//методы класса MasterInputScreen
void MasterInputScreen::setMaster()
{
    wcout << L"Введите имя мастера: ";
    cin >> mName;
    wcout << L"Введите оплату: ";
    cin >> mSalary;
    Master* ptrMaster = new Master(mName, mSalary);
    ptrMasterList->instertMaster(ptrMaster);
}

