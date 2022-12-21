#include <fixorder.h>

using namespace std;

FixOrder::FixOrder(int d, int m, string an, string cn, string mn):
    day(d), month(m), autoName(an), clientName(cn), masterName(mn)
{

}

FixOrder::~FixOrder()
{

}

int FixOrder::getDay()
{
    return day;
}

int FixOrder::getMonth()
{
    return month;
}

string FixOrder::getAutoName()
{
    return autoName;
}

string FixOrder::getClientName()
{
    return clientName;
}

string FixOrder::getMasterName()
{
    return masterName;
}

void FixOrder::getSparePart()
{
    ptrSparePart->display(clientName, month);
    return;
}

int FixOrder::getTotalPrice()
{
    return 777;
}

FixOrderList::~FixOrderList()
{
    while(!setPtrsFixOrder.empty())
    {
        iter = setPtrsFixOrder.begin();
        delete *iter;
        setPtrsFixOrder.erase(iter);
    }
}

void FixOrderList::insertSparePart(FixOrder* ptrFO)
{
    setPtrsFixOrder.push_back(ptrFO);
}

bool FixOrderList::display()
{
    wcout << L"Заказ-наряд на услуги: \n";
    if(setPtrsFixOrder.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return false;
    }
    else
    {
        iter = setPtrsFixOrder.begin();
        wcout << L"Date\tAuto\tClient\tMaster\n";

        while(iter != setPtrsFixOrder.end())
        {
            cout << (*iter)->getDay() << "." << (*iter)->getMonth() << "\t"
                  << (*iter)->getAutoName() << "\t" << (*iter)->getClientName() << "\t"
                  << (*iter)->getMasterName() << "\n";
            *iter++;
        }
    }
    return true;
}


FixOrderInputScreen::FixOrderInputScreen(FixOrderList* ptrFO, ClientList* ptrCL, MasterList* ptrML, SalaryRecord* ptrSR, SparePartList* ptrSPL, ServiceList* ptrSL):
    ptrFixOrderList(ptrFO), ptrClientList(ptrCL), ptrMasterList(ptrML), ptrSalaryRecord(ptrSR),  ptrSparePartList(ptrSPL), ptrServiceList(ptrSL)
{
    ptrClientInputScreen = new ClientInputScreen(ptrClientList);
}
void FixOrderInputScreen::setFixOrder()
{
//    if(!ptrMasterList->display())
//    {
//        system("cls");
//        wcout << L"Список мастеров пуст. Для заполнения этого документа добавьте мастера в список";
//        getch();
//        return;
//    }

    if(ptrMasterList->isEmpty())
    {
        wcout << L"Список мастеров пуст. \nДля заполнения этого документа добавьте мастера в список.\n";
        getch();
        system("cls");
        return;
    }
    else
    {

        wcout << L"ДАТА\n";
        wcout << L"Введите день: ";
        cin >> day;
        wcout << L"Введите месяц: ";
        cin >> month;

        ptrClientInputScreen->setClient();
        clientName = ptrClientInputScreen->getName();
        autoName = ptrClientInputScreen->getAutoName();

        wcout << L"МАСТЕР\n";
        bool tmp = true;
        ptrMasterList->display();
        while(tmp)
        {
            wcout << L"Введите имя мастера из списка: ";
            cin >> masterName;
            if(ptrMasterList->isExisting(masterName))
                tmp = false;
            else
            {
                wcout << L"Ошибка. Такого мастера нет в списке.\n";

            }
        }
        ptrSalaryRecord->insertSalary(masterName, month);

        ptrSparePartList->display();
        SparePartInputScreen* ptrSPIS = new SparePartInputScreen(ptrSparePartList);
        ptrSPIS->setSparePart(month, clientName);

        ServiceInputScreen* ptrSIS = new ServiceInputScreen(ptrServiceList);
        ptrSIS->setService(month, clientName);

        FixOrder* ptrFO = new FixOrder(day, month, autoName, clientName, masterName);
        ptrFixOrderList->insertSparePart(ptrFO);


    }



}
