#include "salary.h"

using namespace std;

//методы класса SalaryRow
SalaryRow::SalaryRow(string n, int s): masterName(n), masterSalary(s)
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
 void SalaryRow::setMasterSalary(int sum)
 {
     masterSalary = sum;
 }

 int SalaryRow::getMasterSalary()
 {
     return masterSalary;
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

void SalaryRecord::insertSalary(string masterName, int masterSalary, int month)
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
    SalaryRow* ptrRow = new SalaryRow(masterName, masterSalary);
    ptrRow->setSalary(month);
    setPtrsSR.push_back(ptrRow);
}

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


            cout<<(*iter)->getMasterName().substr(0,6);

            for(int i = 0; i < 12; i++)
            {
                cout<<"\t"<<(*iter)->getSalaryFor(i);
            }
            int total = (*iter)->getSumOfSalary();
            int sal = (*iter)->getMasterSalary();
            cout << "\t" << total << "\t" << total*sal << "\n";
            iter++;
        }
        wcout << L"Итог в  у.е.: " << getSumOfSalaries() << "\n";

    }
}

int SalaryRecord::getSumOfSalaries()
{
    int sum = 0;
    iter = setPtrsSR.begin();
    while(iter != setPtrsSR.end())
    {
        sum = sum + ((*iter)->getSumOfSalary() * (*iter)->getMasterSalary());
        iter++;
    }

    return sum;
}

void SalaryRecord::setMasterSalary(string name, int sum)
{
    iter = setPtrsSR.begin();
    while(iter != setPtrsSR.end())
    {
        if ((*iter)->getMasterName() == name)
        {
            (*iter)->setMasterSalary(sum);
        }
    }
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
            int sum = ptrMasterList->getSal(masterName);
            ptrSalaryRecord->insertSalary(masterName, sum, month);

            ptrSalaryRecord->setMasterSalary(masterName, sum);
        }

    }
}
