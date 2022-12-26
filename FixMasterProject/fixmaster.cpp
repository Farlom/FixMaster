#include "fixmaster.h"

using namespace std;

UserInterface::UserInterface()
{
    ptrMasterList = new MasterList;
    ptrSparePartList = new SparePartList;
    ptrClientList = new ClientList;
    ptrServiceList = new ServiceList;
    ptrFixOrderList = new FixOrderList;
    ptrShipOrderList = new ShipOrderList;
    ptrSalaryRecord = new SalaryRecord;
//    ptrExpenseRecord = new ExpenseRecord;
    ptrAnnualReport = new AnnualReport(ptrSalaryRecord, ptrSparePartList, ptrServiceList);
}

UserInterface::~UserInterface()
{
    delete ptrMasterList;
    delete ptrClientList;
    delete ptrSparePartList;
    delete ptrServiceList;
    delete ptrSalaryRecord;
    delete ptrFixOrderList;
    delete ptrShipOrderList;
//    delete ptrExpenseRecord;
}

void UserInterface::start()
{

    //start data
//    Master* m1 = new Master(10, "Oleg", 120);
//    Master* m2 = new Master(20, "Bezrukov", 200);
//    ptrMasterList->instertMaster(m1);
//    ptrMasterList->instertMaster(m2);
//    ptrSalaryRecord->insertSalary("Oleg", 120, 12);
//    ptrSalaryRecord->insertSalary("Bezrukov", 200, 12);
//    ptrSalaryRecord->insertSalary("Bezrukov", 200, 10);

//    Client* c1 = new Client("Zhenya", "Polo");
//    Client* c2 = new Client("Pavel", "Passat");
//    SparePart* sp1 = new SparePart(1, "belt1", "Zhenya", 1000, 1, 12);
//    SparePart* sp2 = new SparePart(2, "belt2", "Zhenya", 1100, 1, 12);
//    ptrSparePartList->insertSparePart(sp1);
//    ptrSparePartList->insertSparePart(sp2);

    while(true)
    {
//        try {
//          cin >> ch;

//          if (!cin)
//              throw "Input error";
//        }
//        catch(...)
//        {

//        };
//        throw "NAC";
//        getch();
        system("cls");
        wcout << L"1 - режим ввода данных\t2 - режим вывода данных\n";
        wcout << L"0 - выход из программы\nВвод: ";
        cin >> ch;

        if (ch == '0') return;
        if (ch == '1')
        {
            char ch2;
            system("cls");
            wcout << L"РЕЖИМ ВВОДА ДАННЫХ\n";
            wcout << L"1 - добавить нового мастера\t2 - составить заказ наряд на поставки\n";
            wcout << L"3 - составить заказ наряд на услуги ремонта\n";
            wcout << L"0 - назад\nВвод: ";
            cin >> ch2;

            switch(ch2)
            {
            case '0':
                system("CLS");
                break;

            case '1':
                ptrMasterInputScreen = new MasterInputScreen(ptrMasterList);
                ptrMasterInputScreen->setMaster();
                delete ptrMasterInputScreen;
                break;

            case '2':
                ptrShipOrderInputScreen = new ShipOrderInputScreen(ptrShipOrderList, ptrSparePartList);
                ptrShipOrderInputScreen->setShipOrder();
                break;


            case '3':
                ptrFixOrderInputScreen = new FixOrderInputScreen(ptrFixOrderList, ptrClientList, ptrMasterList, ptrSalaryRecord, ptrSparePartList, ptrServiceList);
                ptrFixOrderInputScreen->setFixOrder();
                break;
            }


        }

        if (ch == '2')
        {
            char ch2;
            system("cls");
            wcout << L"РЕЖИМ ВЫВОДА ДАННЫХ\n";
            wcout << L"1 - вывести список мастеров\t2 - вывести зарплатную ведомость\n";
            wcout << L"3 - список з/ч\t4 - список заказ-нарядов на поставки\n";
            wcout << L"5 - список заказ-нарядов на услуги\t6 - годовой отчет\n";
            wcout << L"0 - назад\nВвод: ";
            cin >> ch2;

            switch(ch2)
            {
            case '1':
                system("cls");
                ptrMasterList->display();
                break;

            case '2':
                system("cls");
                ptrSalaryRecord->display();
                getch();
                break;

            case '3':
                system("cls");
                ptrSparePartList->display();
                getch();
                break;

            case '4':
                system("cls");
                ptrShipOrderList->display();
                break;

            case '5':
                system("cls");
                ptrFixOrderList->display();
                break;

            case '6':
                system("cls");
                ptrAnnualReport->display();
                break;
            }
        }
    }
}

