#include "tools.h"

using namespace std;

//методы класса SparePart
SparePart::SparePart(int id, string n, string on, int p, int dd, int mm): ID(id), name(n), ownerName(on), price(p), day(dd), month(mm)
{

}

SparePart::~SparePart()
{

}

string SparePart::getName()
{
    return name;
}

string SparePart::getOwnerName()
{
    return ownerName;
}

int SparePart::getPrice()
{
    return price;
}

int SparePart::getDay()
{
    return day;
}

int SparePart::getMonth()
{
    return month;
}

int SparePart::getID()
{
    return ID;
}

void SparePart::setClient(string cn)
{
   ownerName = cn;
}

//методы класса SparePartList
SparePartList::~SparePartList()
{
    while(!setPtrsSpareParts.empty())
    {
        iter = setPtrsSpareParts.begin();
        delete *iter;
        setPtrsSpareParts.erase(iter);
    }
}

void SparePartList::insertSparePart(SparePart* ptrSP)
{
    setPtrsSpareParts.push_back(ptrSP);
}

void SparePartList::display(string on, int m)
{
    wcout << L"Список з/ч:\n";
    if(setPtrsSpareParts.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return;
    }
    else
    {
        iter = setPtrsSpareParts.begin();
        wcout << L"Name\tPrice\tFor\n";

        while(iter != setPtrsSpareParts.end())
        {
            if ((*iter)->getOwnerName() == on)
            {
                if ((*iter)->getMonth() == m)
                {
                    cout << (*iter)->getName() << "\t"
                         << (*iter)->getPrice() << "\t"
                         << (*iter)->getOwnerName() << "\n";
                }

            }
            *iter++;
        }
        return;
    }
}

void SparePartList::display()
{
    wcout << L"Список з/ч:\n";
    if(setPtrsSpareParts.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return;
    }
    else
    {
        iter = setPtrsSpareParts.begin();
        wcout << L"ID\tName\tPrice\tFor\tDate\n";

        while(iter != setPtrsSpareParts.end())
        {
            cout << (*iter)->getID() << "\t"
                 << (*iter)->getName() << "\t"
                 << (*iter)->getPrice() << "\t"
                 << (*iter)->getOwnerName() << "\t"
                 << (*iter)->getDay() << "."
                 << (*iter)->getMonth() << "\n";
            *iter++;
        }
        return;
    }
}

void SparePartList::display(int dd, int mm)
{
    wcout << L"Список доступных з/ч:\n";
    if(setPtrsSpareParts.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return;
    }
    else
    {
        iter = setPtrsSpareParts.begin();
        wcout << L"ID\tName\tPrice\tFor\tDate\n";

        while(iter != setPtrsSpareParts.end())
        {
            if(mm >= (*iter)->getMonth() || (mm == (*iter)->getMonth() && dd == (*iter)->getDay()))
            {
                if((*iter)->getOwnerName() == "0")
                {
                    cout << (*iter)->getID() << "\t"
                         << (*iter)->getName() << "\t"
                         << (*iter)->getPrice() << "\t"
                         << (*iter)->getOwnerName() << "\t"
                         << (*iter)->getDay() << "."
                         << (*iter)->getMonth() << "\n";
                }
            }

            *iter++;
        }
        return;
    }
}


bool SparePartList::isEmpty()
{
    return setPtrsSpareParts.empty();
}

void SparePartList::displayByID(int id)
{
    iter = setPtrsSpareParts.begin();
    wcout << L"Наименование\tЦена\n";
    while(iter != setPtrsSpareParts.end())
    {
        if (id == (*iter)->getID())
            cout << (*iter)->getName() << "\t\t" << (*iter)->getPrice() << "\n";
        *iter++;
    }
}

bool SparePartList::isExisting(int id)
{
    iter = setPtrsSpareParts.begin();
    while(iter != setPtrsSpareParts.end())
    {
        if((*iter)->getID() == id)
            return true;
        else *iter++;
    }
    return false;
}



void SparePartList::updateSparePart(int id, string cn)
{
    iter = setPtrsSpareParts.begin();
    while(iter != setPtrsSpareParts.end())
    {
        if((*iter)->getID() == id)
        {
            (*iter)->setClient(cn);
            return;
        }
        else *iter++;
    }
    return;
}

string SparePartList::getName(int id)
{
    iter = setPtrsSpareParts.begin();
    while (iter != setPtrsSpareParts.end())
    {
        if ((*iter)->getID() == id)
        {
            return (*iter)->getName();
        }
        else *iter++;

    }
    return "Not found";
}

int SparePartList::getPrice(int id)
{
    iter = setPtrsSpareParts.begin();
    while (iter != setPtrsSpareParts.end())
    {
        if ((*iter)->getID() == id)
        {
            return (*iter)->getPrice();
        }
        else *iter++;
    }
    return -1;
}

int SparePartList::length()
{
    int len = 0;
    iter = setPtrsSpareParts.begin();
    while(iter != setPtrsSpareParts.end())
    {

     len++;
     *iter++;
    }
    return len + 1;
}

int SparePartList::getTotalPrice(bool free)
{
    int sum = 0;
    if(free)
    {

        iter = setPtrsSpareParts.begin();
        while(iter != setPtrsSpareParts.end())
        {
            sum += (*iter)->getPrice();
            *iter++;
        }
    }
    else if(!free)
    {
//        sum = 5000;
        iter = setPtrsSpareParts.begin();
        while(iter != setPtrsSpareParts.end())
        {
            if((*iter)->getOwnerName() != "0")
            {
                sum += (*iter)->getPrice();
            }
            *iter++;
        }
    }
    return sum;
}

bool SparePartList::isFree(int id)
{
    iter = setPtrsSpareParts.begin();
    while(iter != setPtrsSpareParts.end())
    {
        if((*iter)->getID() == id)
        {
            if((*iter)->getOwnerName() == "0")
            {
                return true;
            }
        }
        *iter++;
    }
    return false;
}


//методы класса SparePartInputScreen
void SparePartInputScreen::setSparePart(int dd, int mm, string n)
{
    wcout << L"Введите наименование з.ч.: ";
    cin >> sparePartName;
    wcout << L"Введите стоимость з.ч.: ";
    cin >> price;
    ownerName = n;
    day = dd;
    month = mm;
    ID = ptrSparePartList->length();

    SparePart* ptr = new SparePart(ID, sparePartName, n, price, dd, mm);
    ptrSparePartList->insertSparePart(ptr);
        //ptrSparePartList->setID(ptr, ID);

}
string SparePartInputScreen::getSparePartName()
{
    return sparePartName;
}

int SparePartInputScreen::getSparePartPrice()
{
    return price;
}

Service::Service(string n, string on, int p, int d, int m): name(n), ownerName(on), price(p), day(d), month(m)
{

}

Service::~Service()
{

}

int Service::getDay()
{
    return day;
}

string Service::getName()
{
    return name;
}

string Service::getOwnerName()
{
    return ownerName;
}

int Service::getPrice()
{
    return price;
}

int Service::getMonth()
{
    return month;
}

ServiceList::~ServiceList()
{
    while(!setPtrsServices.empty())
    {
        iter = setPtrsServices.begin();
        delete *iter;
        setPtrsServices.erase(iter);
    }
}

void ServiceList::insertService(Service* ptrS)
{
    setPtrsServices.push_back(ptrS);
}

void ServiceList::display()
{
    wcout << L"Список услуг:\n";
    if(setPtrsServices.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return;
    }
    else
    {
        wcout << L"Month\tName\tPrice\tFor\n";
        iter = setPtrsServices.begin();
        while(iter != setPtrsServices.end())
        {
            cout << (*iter)->getMonth() << "\t" <<
                    (*iter)->getName() << "\t" <<
                    (*iter)->getPrice() << "\t" <<
                    (*iter)->getOwnerName() <<"\n";
            *iter++;
        }
        return;
    }
}

void ServiceList::display(string on, int m)
{
    wcout << L"Список услуг:\n";
    if(setPtrsServices.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return;
    }
    else
    {
        iter = setPtrsServices.begin();
        wcout << L"Name\tPrice\tFor\n";

        while(iter != setPtrsServices.end())
        {
            if ((*iter)->getOwnerName() == on)
            {
                if ((*iter)->getMonth() == m)
                {
                    cout << (*iter)->getName() << "\t" << (*iter)->getPrice() << "\t" << (*iter)->getOwnerName() << "123\n";
                }

            }
            *iter++;
        }
        return;
    }
}

int ServiceList::getTotalServices()
{
    int sum = 0;
    iter = setPtrsServices.begin();
    while(iter != setPtrsServices.end())
    {
        sum += (*iter)->getPrice();
        *iter++;
    }
    return sum;
}

void ServiceInputScreen::setService(int d, int m, string n)
{
    wcout << L"Введите наименование услуги: ";
    cin >> serviceName;
    wcout << L"Введите стоимость услуги: ";
    cin >> price;
    ownerName = n;
    month = m;
    Service* ptr = new Service(serviceName, n, price, d, m);
    ptrServiceList->insertService(ptr);

}

string ServiceInputScreen::getName()
{
    return serviceName;
}

int ServiceInputScreen::getPrice()
{
    return price;
}
