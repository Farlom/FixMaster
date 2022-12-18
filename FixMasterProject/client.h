#ifndef CLIENT
#define CLIENT

#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

class Client //клиент сервиса
{
private:
    string name, autoName;

public:
    Client(string n, string an);
    ~Client();
    string getName();
    string getAutoName();
};

class ClientList
{
private:
    list<Client*> setPtrsClients;
    list<Client*>::iterator iter;

public:
    ~ClientList();
    void insertClient(Client*);
    bool display();
};

class ClientInputScreen
{
private:
    ClientList* ptrClientList;
    string clientName, autoName;

public:
    ClientInputScreen(ClientList* ptrCL): ptrClientList(ptrCL)
    {

    }

    void setClient();
    void setClient(ClientList* ptrCL, string cn, string an);
    string getName();
    string getAutoName();
};

#endif // CLIENT

