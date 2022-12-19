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

Service::Service(string n, string on, int p, int m)
{
//todo
}

Service::~Service()
{
//todo
}


string Service::getName()
{
   //todo
}

string Service::getOwnerName()
{
//todo
}

int Service::getPrice()
{
//todo
}

int Service::getMonth()
{
//todo
}

ServiceList::~ServiceList()
{
    //todo
}

void ServiceList::insertService(Service* ptrS)
{
//todo
}

void ServiceList::display()
{
    //todo
}

void ServiceList::display(string on, int m)
{
    //todo
}

void ServiceInputScreen::setService(int m, string n)
{
    //todo
}
