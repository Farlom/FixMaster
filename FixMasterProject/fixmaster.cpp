#include <iostream>
#include "fixmaster.h"


//методы класса Master
Master::Master(string n, int s): name(n), salary(s)
{

}

Master::~Master()
{

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
    //TODO
}

void MasterList::instertMaster(Master* ptrM)
{
    //TODO
}

int MasterList::getSal(string mName)
{
    //TODO
}

void MasterList::display()
{
    //TODO
}

//методы класса MasterInputScreen
void MasterInputScreen::setMaster()
{
    //TODO
}

