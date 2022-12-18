#include <salary.h>

using namespace std;

SalaryRow::SalaryRow(string n): masterName(n)
{
    fill(&salary[0], &salary[12], 0); //çàïîëíÿåì ìàññèâ íóëÿìè

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


//ìåòîäû êëàññà SalaryRecord
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
     * èíêðåìåíòèðóåò ñ÷åò÷èê ðàáîò ó ìàñòåðà masterName â ìåñÿöå month
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
    //âûâîäèò òàáëèöó "Çàðïëàòíàÿ âåäîìîñòü" (âîçìîæíî, åùå ïðèäåòñÿ óìíîæàòü íà çï ìàñòåðà)
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
    //âûâîäèò ñóììó âñåõ îïëàò ìàñòåðàì
}


//ìåòîäû êëàññà SalaryInputScreen
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
    /* ïîëó÷èòü èìÿ ìàñòåðà
     * åñëè èìÿ íàéäåíî (è òàêîé ìàñòåð ñóùåñòâóåò)
     * èíêðåìåíòèðóåì
     */
}
