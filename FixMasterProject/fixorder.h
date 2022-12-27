    #ifndef FIXORDER
#define FIXORDER

#include <iostream>
#include <tools.h>
#include "client.h"
#include "master.h"
#include "salary.h"

using namespace std;

class FixOrder
{
private:
    int ID;
    int day, month;
    string autoName, clientName, masterName;

    int sparePartID;
    string sparePartName;
    int sparePartPrice;

    string serviceName;
    int servicePrice;
//    SparePart* ptrSparePart;
//    SparePartList* ptrSparePartList;
    //vector<string> sparePartName;
    //vector<int> sparePartPrice;

    int totalPrice;

public:
    //FixOrder(int d, int m, string an, string cn, string mn, vector<string> spn, vector<int> spp);
    FixOrder(int id, int dd, int mm, string aname, string cname, string mname, string spname, int spprice, string servicen, int servicep);//, SparePart* ptrSP);
    ~FixOrder();
    int getID();
    int getDay();
    int getMonth();
    string getAutoName();
    string getClientName();
    string getMasterName();
    int getSparePartID();
    string getSparePartName();
    int getSparePartPrice();
    string getServiceName();
    int getServicePrice();
    void getSparePart();
    int getTotalPrice();
    void setTotalPrice(int amount);
};

class FixOrderList
{
private:
    list<FixOrder*> setPtrsFixOrder;
    list<FixOrder*>::iterator iter;
    SparePartList* ptrSparePartList;

public:
    FixOrderList();
    ~FixOrderList();
    void insertSparePart(FixOrder*);
//    int getID();
    void display();
    bool display(string ownerN);
    void displayByID(int id);
    void updateTotalPrice(int id, int amount);
    int getTotalIncome();
};

class FixOrderInputScreen
{
private:

    FixOrderList* ptrFixOrderList;

    ClientList* ptrClientList;
    ClientInputScreen* ptrClientInputScreen;

    MasterList* ptrMasterList;

    SalaryRecord* ptrSalaryRecord;
    SalaryInputScreen* ptrSalaryInputScreen;

    SparePartInputScreen* ptrSparePartInputScreen;
    SparePartList* ptrSparePartList; //+

    ServiceInputScreen* ptrServiceInputScreen;
    ServiceList* ptrServiceList; //+

    static int ID;
    int day, month, masterID, sparePartID, serviceID;
    string autoName, clientName, masterName;
    string sparePartName;
    int sparePartPrice;

    string serviceName;
    int servicePrice;

    int totalPrice;

public:
//    FixOrderInputScreen(FixOrderList* pFOL, ClientList* pCL, MasterList* pML, SparePartInputScreen* pSPIS):
//        ptrFixOrderList(pFOL), ptrClientList(pCL), ptrMasterList(pML), ptrSparePartInputScreen(pSPIS)
    FixOrderInputScreen(FixOrderList* ptrFO, ClientList* ptrCL, MasterList* ptrML, SalaryRecord* ptrSR, SparePartList* ptrSPL, ServiceList* ptrSL);
    //FixOrderInputScreen();


    void setFixOrder();
};



#endif // FIXORDER

