#include <shiporder.h>

using namespace std;

ShipOrder::ShipOrder(int dd, int mm, string spn, int spp):
    day(dd), month(mm), sparePartName(spn), sparePartPrice(spp)
{

}

ShipOrder::~ShipOrder()
{

}

int ShipOrder::getDay()
{
    return day;
}

int ShipOrder::getMonth()
{
    return month;
}

string ShipOrder::getSparePartName()
{
    return sparePartName;
}

int ShipOrder::getSparePartPrice()
{
    return sparePartPrice;
}

ShipOrderList::~ShipOrderList()
{
    while(!setPtrsShipOrder.empty())
    {
        iter = setPtrsShipOrder.begin();
        delete *iter;
        setPtrsShipOrder.erase(iter);
    }
}

void ShipOrderList::insert(ShipOrder* ptrSO)
{
    setPtrsShipOrder.push_back(ptrSO);
}

int ShipOrderList::getTotalPrice()
{
    int sum = 0;
    iter = setPtrsShipOrder.begin();
    while(iter != setPtrsShipOrder.end())
    {
        sum = sum + (*iter)->getSparePartPrice();
        iter++;
    }

    return sum;
}

void ShipOrderList::display()
{
    wcout << L"Заказ-наряд на поставки: \n";
    if(setPtrsShipOrder.empty())
    {
            wcout << L"Список пуст. Для продолжения нажмите любую клавишу...";
            getch();
            system("cls");
            return;
    }
    else
    {
        iter = setPtrsShipOrder.begin();
        wcout << L"Date\tName\tPrice\n";

        while(iter != setPtrsShipOrder.end())
        {
            cout << (*iter)->getDay() << '.' <<
                    (*iter)->getMonth() << "\t" <<
                    (*iter)->getSparePartName() << "\t" <<
                    (*iter)->getSparePartPrice() << "\n";
            *iter++;
        }
    }
    return;
}

ShipOrderInputScreen::ShipOrderInputScreen(ShipOrderList* ptrSOL, SparePartList* ptrSPL):
    ptrShipOrderList(ptrSOL), ptrSparePartList(ptrSPL)
{
    ptrSparePartInputScreen = new SparePartInputScreen(ptrSparePartList);
}


void ShipOrderInputScreen::setShipOrder()
{
    wcout << L"ДАТА\nВведите день: ";
    cin >> day;
    wcout << L"Введите месяц: ";
    cin >> month;

    bool tmp = true;
    while(tmp)
    {
        char choice;
        ptrSparePartInputScreen->setSparePart(month, "0");

        bool err = false;
        do
        {
            wcout << L"Продолжить добавление? (y/n): ";
            cin >> choice;

            switch(choice)
            {
            case 'y':
                err = false;
                break;
            case 'Y':
                err = false;
                break;
            case 'n':
                tmp = false;
                err = false;
                break;
            case 'N':
                tmp = false;
                err = false;
                break;
            default:
                wcout << L"Ошибка.";
                err = true;
                break;
            }
        } while(err);

    }
}
