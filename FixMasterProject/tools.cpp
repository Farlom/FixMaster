#include <tools.h>

using namespace std;

SparePart::SparePart(string n, string on, int p, int m): name(n), ownerName(on), price(p), month(m)
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

int SparePart::getMonth()
{
    return month;
}

//void SparePart::setClient(string cn)
//{
//   ownerName = cn;
//}

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
                    cout << (*iter)->getName() << "\t" << (*iter)->getPrice() << "\t" << (*iter)->getOwnerName() << "123\n";
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
        wcout << L"Name\tPrice\tFor\n";

        while(iter != setPtrsSpareParts.end())
        {
            cout << (*iter)->getName() << "\t" << (*iter)->getPrice() << "\t" << (*iter)->getOwnerName() << "\n";
            *iter++;
        }
        return;
    }
}

//методы класса SparePartInputScreen
void SparePartInputScreen::setSparePart(int m, string n)
{
    wcout << L"Введите наименование з.ч.: ";
    cin >> sparePartName;
    wcout << L"Введите стоимость з.ч.: ";
    cin >> price;
    ownerName = n;
    month = m;
    SparePart* ptr = new SparePart(sparePartName, n, price, m);
    ptrSparePartList->insertSparePart(ptr);
}

Service::Service(string n, string on, int p, int m): name(n), ownerName(on), price(p), month(m)
{

}

Service::~Service()
{

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

void ServiceInputScreen::setService(int m, string n)
{
    wcout << L"Введите наименование услуги: ";
    cin >> serviceName;
    wcout << L"Введите стоимость услуги: ";
    cin >> price;
    ownerName = n;
    month = m;
    Service* ptr = new Service(serviceName, n, price, m);
    ptrServiceList->insertService(ptr);
//    cout<<ptr->getOwnerName();

//    wcout << L"Введите ID: ";
//    cin >> ID;
//    wcout << L"\nВведите название: ";
//    cin >> serviceName;
//    wcout << L"\nВведите стоимость: ";
//    cin >> price;
//    Service* ptrService = new Service(ID, serviceName, price);
//    ptrServiceList->insertService(ptrService);
}
