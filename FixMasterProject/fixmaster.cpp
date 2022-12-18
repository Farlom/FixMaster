#include "fixmaster.h"

using namespace std;

UserInterface::UserInterface()
{
    ptrMasterList = new MasterList;
    ptrSalaryRecord = new SalaryRecord;
    ptrClientList = new ClientList;
}

UserInterface::~UserInterface()
{
    delete ptrMasterList;
    delete ptrSalaryRecord;
    delete ptrClientList;
}

void UserInterface::start()
{
    while(true)
        {
            wcout << L"1 - ????? ????? ??????\t2 - ????? ?????? ??????\n";
            wcout << L"0 - ????? ?? ?????????\n????: ";
            cin >> ch;

            if (ch == '0') return;
            if (ch == '1')
            {
                char ch2;
                system("cls");
                wcout << L"????? ????? ??????\n";
                wcout << L"1 - ???????? ?????? ???????\t2 - ????????? ????? ????? ?? ?????? ???????\n";
                wcout << L"3 - ??????\n";
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
                }


            }

            if (ch == '2')
            {
                char ch2;
                system("cls");
                wcout << L"????? ?????? ??????\n";
                wcout << L"1 - ??????? ?????? ????????\t2 - ??????? ?????????? ?????????\n";
                wcout << L"3 - 5 - ??????\n";
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
                }
            }
        }
}


