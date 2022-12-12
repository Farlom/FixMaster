#include <iostream>
#include <conio.h> //getch();
#include "fixmaster.h"

//РјРµС‚РѕРґС‹ РєР»Р°СЃСЃР° Master
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

//РјРµС‚РѕРґС‹ РєР»Р°СЃСЃР° MasterList
MasterList::~MasterList()
{
    //СѓРґР°Р»СЏРµРј СѓРєР°Р·Р°С‚РµР»Рё РёР· РєРѕРЅС‚РµР№РЅРµСЂР°
    while (!setPtrsMasters.empty())
    {
        iter = setPtrsMasters.begin();
        delete *iter;
        setPtrsMasters.erase(iter);
    }
}

void MasterList::instertMaster(Master* ptrM)
{
    //РІСЃС‚Р°РІРёС‚СЊ РІ РєРѕРЅРµС† list`Р°
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
    //РЅРµ РЅР°С€РµР» = -1
    return -1;
}

bool MasterList::display()
{
    wcout << L"РЎРїРёСЃРѕРє РјР°СЃС‚РµСЂРѕРІ: \n";
    if (setPtrsMasters.empty())
    {
       wcout << L"РЎРїРёСЃРѕРє РїСѓСЃС‚.\nР”Р»СЏ РїСЂРѕРґРѕР»Р¶РµРЅРёСЏ РЅР°Р¶РјРёС‚Рµ Р»СЋР±СѓСЋ РєР»Р°РІРёС€Сѓ...";
       getch();
       system("cls");
       return false;
    }
    else
    {
        wcout << L"РРјСЏ\tРћРєР»Р°Рґ\n";
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

//РјРµС‚РѕРґС‹ РєР»Р°СЃСЃР° MasterInputScreen
void MasterInputScreen::setMaster()
{
    wcout << L"Р’РІРµРґРёС‚Рµ РёРјСЏ РјР°СЃС‚РµСЂР°: ";
    cin >> mName;
    wcout << L"Р’РІРµРґРёС‚Рµ РѕРїР»Р°С‚Сѓ: ";
    cin >> mSalary;
    Master* ptrMaster = new Master(mName, mSalary);
    ptrMasterList->instertMaster(ptrMaster);
}

//методы класса SalaryRow
SalaryRow::SalaryRow(string n): masterName(n)
{
    fill(&salary[0], &salary[12], 0); //заполняем массив нулями

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


//методы класса SalaryRecord
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
     * инкрементирует счетчик работ у мастера masterName в месяце month
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
    wcout << L"Зарплатная ведомость\n";

    iter = setPtrsSR.begin();
    if(setPtrsSR.begin() == setPtrsSR.end())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        return;
    }
    else
    {
        wcout << L"Имя\tЯнварь\tФевраль\tМарт\tАпрель\tМай\tИюнь\tИюль\tАвгуст\tСент-рь\tОктябрь\tНоябрь\tДекабрь\tИтого\n";
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
    //выводит таблицу "Зарплатная ведомость" (возможно, еще придется умножать на зп мастера)
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
    //выводит сумму всех оплат мастерам
}


//методы класса SalaryInputScreen
void SalaryInputScreen::setSalary()
{
    //wcout<< L"SalaryInputScreen.setSalary() \n";

    if (!ptrMasterList->display())
    {
        return;
    }
    else {

        wcout<<L"Введите имя мастера: ";

        cin >> masterName;
        if (ptrMasterList->getSal(masterName) == -1)
        {
            wcout << L"Такого мастера нет в списке!";
            getch();
            system("cls");
            return;
        }
        else
        {
            wcout << L"\nВведите месяц, в котором выполнялись работы: ";
            cin >> month;
            ptrSalaryRecord->insertSalary(masterName, month);
        }

    }

    //TODO
    /* получить имя мастера
     * если имя найдено (и такой мастер существует)
     * инкрементируем
     */
}


