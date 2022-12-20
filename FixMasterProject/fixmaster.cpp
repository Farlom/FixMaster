#include "fixmaster.h"

using namespace std;

UserInterface::UserInterface()
{
    ptrMasterList = new MasterList;
    ptrSparePartList = new SparePartList;
    ptrSalaryRecord = new SalaryRecord;
    ptrClientList = new ClientList;
    ptrServiceList = new ServiceList;
}

UserInterface::~UserInterface()
{
    delete ptrMasterList;
    delete ptrSparePartList;
    delete ptrSalaryRecord;
    delete ptrClientList;
    delete ptrServiceList;
}

void UserInterface::start()
{
    while(true)
        {
            wcout << L"1 - режим ввода данных\t2 - режим вывода данных\n";
            wcout << L"0 - выход из программы\nВвод: ";
            cin >> ch;

            if (ch == '0') return;
            if (ch == '1')
            {
                char ch2;
                system("cls");
                wcout << L"РЕЖИМ ВВОДА ДАННЫХ\n";
                wcout << L"1 - добавить нового мастера\t2 - ????????? ????? ????? ?? ?????? ???????\n";
                wcout << L"3 - ??????\t4 - vvod z.ch.\n 5-Сервис\n";
                wcout << L"0 - ?????\n????: ";
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
                    ptrSalaryInputScreen = new SalaryInputScreen(ptrMasterList, ptrSalaryRecord);
                    ptrSalaryInputScreen->setSalary();
                    break;

                case '3':
                    ptrClientInputScreen = new ClientInputScreen(ptrClientList);
                    ptrClientInputScreen->setClient();
                    break;
                case '4':
                    ptrSparePartInputScreen = new SparePartInputScreen(ptrSparePartList);
                    ptrSparePartInputScreen->setSparePart(NULL, "123");
                    break;
                case '5':
                    ptrServiceInputScreen = new ServiceInputScreen(ptrServiceList);
                    ptrServiceInputScreen->setService(NULL, "123");
                    break;
                }


            }

            if (ch == '2')
            {
                char ch2;
                system("cls");
                wcout << L"РЕЖИМ ВЫВОДА ДАННЫХ\n";
                wcout << L"1 - ??????? ?????? ????????\t2 - ??????? ?????????? ?????????\n";
                wcout << L"3 - 4 - vivod z.ch. 5-Вывод услуг\n 6 - ??????\n";
                wcout << L"0 - ?????\n????: ";
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
                    ptrClientList->display();
                    break;

                case '4':
                    system("cls");
                    ptrSparePartList->display();
                    break;
                case '5':
                    system("cls");
                    ptrServiceList->display();
                    break;
                }
            }
        }
}


