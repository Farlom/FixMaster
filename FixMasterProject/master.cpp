#include <master.h>

using namespace std;

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

//Ð¼ÐµÑÐ¾Ð´Ñ ÐºÐ»Ð°ÑÑÐ° MasterList
MasterList::~MasterList()
{
    //ÑÐ´Ð°Ð»ÑÐµÐ¼ ÑÐºÐ°Ð·Ð°ÑÐµÐ»Ð¸ Ð¸Ð· ÐºÐ¾Ð½ÑÐµÐ¹Ð½ÐµÑÐ°
    while (!setPtrsMasters.empty())
    {
        iter = setPtrsMasters.begin();
        delete *iter;
        setPtrsMasters.erase(iter);
    }
}

void MasterList::instertMaster(Master* ptrM)
{
    //Ð²ÑÑÐ°Ð²Ð¸ÑÑ Ð² ÐºÐ¾Ð½ÐµÑ list`Ð°
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
    //Ð½Ðµ Ð½Ð°ÑÐµÐ» = -1
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

//Ð¼ÐµÑÐ¾Ð´Ñ ÐºÐ»Ð°ÑÑÐ° MasterInputScreen
void MasterInputScreen::setMaster()
{
    wcout << L"Введите имя мастера: ";
    cin >> mName;
    wcout << L"Введите оплату: ";
    cin >> mSalary;
    Master* ptrMaster = new Master(mName, mSalary);
    ptrMasterList->instertMaster(ptrMaster);
}
