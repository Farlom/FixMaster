#include "client.h"

using namespace std;

Client::Client(string n, string an): name(n), autoName(an)
{

}

Client::~Client()
{

}

string Client::getName()
{
    return name;
}

string Client::getAutoName()
{
    return autoName;
}

ClientList::~ClientList()
{
    while(!setPtrsClients.empty())
    {
        iter = setPtrsClients.begin();
        delete *iter;
        setPtrsClients.erase(iter);
    }
}

void ClientList::insertClient(Client* ptrC)
{
    setPtrsClients.push_back(ptrC);
}

bool ClientList::display()
{
    wcout << L"Список клиентов:\n";
    if(setPtrsClients.empty())
    {
        wcout << L"Список пуст.\nДля продолжения нажмите любую клавишу...";
        getch();
        system("cls");
        return false;
    }
    else
    {
        wcout << L"Имя\tАвтомобиль\n";
        iter = setPtrsClients.begin();
        while(iter != setPtrsClients.end())
        {
            cout << (*iter)->getName() << "\t" << (*iter)->getAutoName() << "\n";
            *iter++;
        }
        return true;
    }
}

void ClientInputScreen::setClient()
{
    wcout << L"Введите имя клиента: ";
    cin >> clientName;
    wcout << L"Введите автомобиль: ";
    cin >> autoName;
    Client* ptrClient = new Client(clientName, autoName);
    ptrClientList->insertClient(ptrClient);
}

void ClientInputScreen::setClient(ClientList* ptrCL, string cn, string an)
{
    Client* ptrClient = new Client(cn, an);
    ptrCL->insertClient(ptrClient);
}

string ClientInputScreen::getName()
{
    return clientName;
}

string ClientInputScreen::getAutoName()
{
    return autoName;
}
