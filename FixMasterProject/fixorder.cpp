#include "fixorder.h"

using namespace std;

FixOrder::FixOrder(int id, int d, int m, string an, string cn, string mn, string spname, int spprice, string servicen, int servicep)://, SparePart* ptrSP):
    ID(id), day(d), month(m), autoName(an), clientName(cn), masterName(mn), sparePartName(spname), sparePartPrice(spprice), serviceName(servicen), servicePrice(servicep)
{

}

FixOrder::~FixOrder()
{

}

int FixOrder::getID()
{
    return ID;
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

string FixOrder::getSparePartName()
{
    return sparePartName;
}

int FixOrder::getSparePartPrice()
{
    return sparePartPrice;
}

string FixOrder::getServiceName()
{
    return serviceName;
}

int FixOrder::getServicePrice()
{
    return servicePrice;
}

int FixOrder::getSparePartID()
{
    return sparePartID;
}

int FixOrder::getTotalPrice()
{
    return totalPrice;
}

void FixOrder::setTotalPrice(int amount)
{
    totalPrice = amount;
}

FixOrderList::FixOrderList()
{

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


void FixOrderList::display()
{
    int prevID = -1;
    wcout << L"Заказ-наряды на услуги: \n";
    if(setPtrsFixOrder.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");

    }
    else
    {
        iter = setPtrsFixOrder.begin();
        wcout << L"ID\tDate\tAuto\tClient\tMaster\tPrice\n";

        while(iter != setPtrsFixOrder.end())
        {
            if ((*iter)->getID() != prevID)
            {
                cout << (*iter)->getID() << "\t"
                     <<(*iter)->getDay() << "." << (*iter)->getMonth() << "\t"
                     << (*iter)->getAutoName() << "\t" << (*iter)->getClientName() << "\t"
                     << (*iter)->getMasterName() << "\t"<< (*iter)->getTotalPrice() <<"\n";
                prevID = (*iter)->getID();
            }
            *iter++;
        }

    }
    int ch;
    if(!setPtrsFixOrder.empty())
    {
        wcout<<L"Ввод: ";
        cin >> ch;
        system("cls");
        displayByID(ch);
    }

//     ptrSparePartList->display();
//    SparePartList* ptrSPL = new SparePartList;
//    ptrSPL->display();

}

void FixOrderList::displayByID(int id)
{
    int price;
    bool tmp = true;
    wcout << L"Заказ-наряд на услуги: \n";
    iter = setPtrsFixOrder.begin();
    while(iter != setPtrsFixOrder.end())
    {
        if((*iter)->getID() == id)
        {
            if(tmp)
            {
                wcout << L"Date\tAuto\tClient\tMaster\n";
                cout << (*iter)->getDay() << "." << (*iter)->getMonth() << "\t"
                      << (*iter)->getAutoName() << "\t" << (*iter)->getClientName() << "\t"
                      << (*iter)->getMasterName() << "\n";
                price = (*iter)->getTotalPrice();

                wcout << L"ЗАПЧАСТИ И РАСХОДНИКИ\n";
                wcout << L"Наименование\tЦена\n";
                tmp = false;
            }


            cout << (*iter)->getSparePartName() << "\t\t" << (*iter)->getSparePartPrice() << "\n";



        }
        *iter++;

    }
    tmp = true;
    iter = setPtrsFixOrder.begin();
    while(iter != setPtrsFixOrder.end())
    {
        if((*iter)->getID() == id)
        {
            if(tmp)
            {
                wcout << L"ВЫПОЛНЕННЫЕ РАБОТЫ\n";
                wcout << L"Наименование\tЦена\n";
                tmp = false;
            }

            cout << (*iter)->getServiceName() << "\t\t" << (*iter)->getServicePrice() << "\n";



        }
         *iter++;


    }
    wcout << L"Общая стоимость: " << price << "\n";
    getch();

}

void FixOrderList::updateTotalPrice(int id, int amount)
{
    iter = setPtrsFixOrder.begin();
    while(iter != setPtrsFixOrder.end())
    {
        if ((*iter)->getID() == id)
        {
            (*iter)->setTotalPrice(amount);
        }
        *iter++;
    }
}

int FixOrderList::getTotalIncome()
{
    int result = 0;
    int prevID = -1;
    iter = setPtrsFixOrder.begin();
    while(iter != setPtrsFixOrder.end())
    {
        if((*iter)->getID() != prevID)
        {
            result += (*iter)->getTotalPrice();
            prevID = (*iter)->getID();
        }

    }
    return result;
}

int FixOrderInputScreen::ID = 1;

FixOrderInputScreen::FixOrderInputScreen(FixOrderList* ptrFO, ClientList* ptrCL, MasterList* ptrML, SalaryRecord* ptrSR, SparePartList* ptrSPL, ServiceList* ptrSL):
    ptrFixOrderList(ptrFO), ptrClientList(ptrCL), ptrMasterList(ptrML), ptrSalaryRecord(ptrSR),  ptrSparePartList(ptrSPL), ptrServiceList(ptrSL)
{
    ptrClientInputScreen = new ClientInputScreen(ptrClientList);
    ptrServiceInputScreen = new ServiceInputScreen(ptrServiceList);
}


void FixOrderInputScreen::setFixOrder()
{
    totalPrice = 0;
    if(ptrMasterList->isEmpty())
    {
        wcout << L"Список мастеров пуст. \nДля заполнения этого документа cоставьте заказ-наряд на поставки.\n";
        getch();
        system("cls");
        return;
    }
    else
    {
        if(ptrSparePartList->isEmpty())
        {
            wcout << L"Список з.ч. пуст. \nДля заполнения этого документа закажите з.ч.\n";
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
                wcout << L"Введите идентификатор мастера из списка: ";
                cin >> masterID;
                if(ptrMasterList->isExisting(masterID))
                {
                    masterName = ptrMasterList->getNameByID(masterID);
                    tmp = false;
                }
                else
                {
                    wcout << L"Ошибка. Такого мастера нет в списке.\n";

                }
            }
            int sum = ptrMasterList->getSal(masterName);
            ptrSalaryRecord->insertSalary(masterName, sum, month);
//            ptrAnnualReport->updateTotalSalaries(ptrSalaryRecord->getSumOfSalaries());
//            ptrAnnualReport


            bool repeat = true;
            do
            {
                ptrSparePartList->display(day, month);
                tmp = true;
                while(tmp)
                {
                    //TODO isExisting and FREE
                    wcout << L"Введите идентификатор з.ч. из списка: ";
                    cin >> sparePartID;

                    if(ptrSparePartList->isExisting(sparePartID))
                    {
                        if(ptrSparePartList->isFree(sparePartID))
                        {


                            ptrSparePartList->updateSparePart(sparePartID, clientName);

                            sparePartName = ptrSparePartList->getName(sparePartID);
                            sparePartPrice = ptrSparePartList->getPrice(sparePartID);
                            totalPrice += sparePartPrice;


                            tmp = false;
                        }
                        else
                        {
                            wcout << L"Ошибка. Такой з.ч. в списке.\n";
                        }
                    }
                }
                ptrServiceInputScreen->setService(day, month, clientName);
                serviceName = ptrServiceInputScreen->getName();
                servicePrice = ptrServiceInputScreen->getPrice();
                totalPrice += servicePrice;

                FixOrder* ptrFO = new FixOrder(ID, day, month, autoName, clientName, masterName, sparePartName, sparePartPrice, serviceName, servicePrice);
                ptrFixOrderList->insertSparePart(ptrFO);

                char choice;
                wcout << L"Продолжить ввод? (y/n): ";
                cin >> choice;
                if (choice == 'n' || choice == 'N') repeat = false;
            }while(repeat);

            cout << serviceName << "\t" << servicePrice << "\t" << totalPrice;
            ptrFixOrderList->updateTotalPrice(ID, totalPrice);
            ID++;
        }


    }
}
