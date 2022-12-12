#include <iostream>
#include <conio.h> //getch();
#include "fixmaster.h"

//методы класса Master
Master::Master(string n, int s): name(n), salary(s)
{
    //rdy
}

Master::~Master()
{
    //rdy
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
    //удаляем указатели из контейнера
    while (!setPtrsMasters.empty())
    {
        iter = setPtrsMasters.begin();
        delete *iter;
        setPtrsMasters.erase(iter);
    }
}

void MasterList::instertMaster(Master* ptrM)
{
    //вставить в конец list`а
    setPtrsMasters.push_back(ptrM);
}

int MasterList::getSal(string mName)
{
    int sal;
    iter = setPtrsMasters.begin();
    while (iter != setPtrsMasters.end())
    {
        sal = (*iter)->getSalary();
        if (mName == ((*iter)->getName()))
        {
            return sal;
        }
        iter++;
    }
    //не нашел = -1
    return -1;
}

bool MasterList::display()
{
    wcout << L"Список мастеров: \n";
    if (setPtrsMasters.empty())
    {
       wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
       getch();
       system("cls");
       return false;
    }
    else
    {
        wcout << L"Имя\tОклад\n";
        iter = setPtrsMasters.begin();
        while (iter != setPtrsMasters.end())
        {
            cout << (*iter)->getName() << "\t" << (*iter)->getSalary() << "\n";
            *iter++;
        }
        return true;
    }
}

bool MasterList::isEmpty()
{
    return setPtrsMasters.empty();
}

bool MasterList::isExisting(string name)
{
    iter = setPtrsMasters.begin();
    while(iter != setPtrsMasters.end())
    {
        if((*iter)->getName() == name)
            return true;
        else *iter++;
    }
    return false;
}

//методы класса MasterInputScreen
void MasterInputScreen::setMaster()
{
    wcout << L"Введите имя мастера: ";
    cin >> mName;
    wcout << L"Введите оплату: ";
    cin >> mSalary;
    Master* ptrMaster = new Master(mName, mSalary);
    ptrMasterList->instertMaster(ptrMaster);
}

//������ ������ SalaryRow
SalaryRow::SalaryRow(string n): masterName(n)
{
    fill(&salary[0], &salary[12], 0); //��������� ������ ������

}

void SalaryRow::setSalary(int month)
{
    salary[month-1]++;
}

string SalaryRow::getMasterName()
{
    return masterName;
}

int SalaryRow::getSalaryFor(int month)
{
    return salary[month];
}

int SalaryRow::getSumOfSalary()
{
    int tmp = 0;
    for (int i = 0; i < 12; i++)
    {
        tmp += salary[i];
    }
    return tmp;
}


//������ ������ SalaryRecord
SalaryRecord::~SalaryRecord()
{
    while(!setPtrsSR.empty())
    {
        iter = setPtrsSR.begin();
        delete *iter;
        setPtrsSR.erase(iter);
    }
}

void SalaryRecord::insertSalary(string masterName, int month)
{
    /*
     * �������������� ������� ����� � ������� masterName � ������ month
     */
    iter = setPtrsSR.begin();
    while(iter != setPtrsSR.end())
    {
        if (masterName == (*iter)->getMasterName())
        {
            (*iter)->setSalary(month);
            return;
        }
        else
            iter++;
    }
    SalaryRow* ptrRow = new SalaryRow(masterName);
    ptrRow->setSalary(month);
    setPtrsSR.push_back(ptrRow);
}

//
void SalaryRecord::display()
{
    wcout << L"���������� ���������\n";

    iter = setPtrsSR.begin();
    if(setPtrsSR.begin() == setPtrsSR.end())
    {
        wcout << L"������ ����.\n��� ����������� ������� ����� �������...";
        getch();
        return;
    }
    else
    {
        wcout << L"���\t������\t�������\t����\t������\t���\t����\t����\t������\t����-��\t�������\t������\t�������\t�����\n";
        while(iter != setPtrsSR.end())
        {

            cout<<(*iter)->getMasterName();

            for(int i = 0; i < 12; i++)
            {
                cout<<"\t"<<(*iter)->getSalaryFor(i);
            }

            cout<<"\t"<<(*iter)->getSumOfSalary()<<"\n";

            iter++;
        }
    }
    //(*iter)->getMasterName();

          //TODO
    //������� ������� "���������� ���������" (��������, ��� �������� �������� �� �� �������)
}

int SalaryRecord::getSumOfSalaries()
{
    int sum = 0;
    iter = setPtrsSR.begin();
    while(iter != setPtrsSR.end())
    {
        sum = sum + (*iter)->getSumOfSalary();
        iter++;
    }

    return sum;
    //TODO
    //������� ����� ���� ����� ��������
}


//������ ������ SalaryInputScreen
void SalaryInputScreen::setSalary()
{
    //wcout<< L"SalaryInputScreen.setSalary() \n";

    if (!ptrMasterList->display())
    {
        return;
    }
    else {

        wcout<<L"������� ��� �������: ";

        cin >> masterName;
        if (ptrMasterList->getSal(masterName) == -1)
        {
            wcout << L"������ ������� ��� � ������!";
            getch();
            system("cls");
            return;
        }
        else
        {
            wcout << L"\n������� �����, � ������� ����������� ������: ";
            cin >> month;
            ptrSalaryRecord->insertSalary(masterName, month);
        }

    }

    //TODO
    /* �������� ��� �������
     * ���� ��� ������� (� ����� ������ ����������)
     * ��������������
     */
}


