#include "annual.h"

using namespace std;

AnnualReport::AnnualReport(SalaryRecord* pSR, SparePartList* pSPL, ServiceList* pSL):
    ptrSR(pSR), ptrSPL(pSPL), ptrSL(pSL)
{

}

void AnnualReport::display()
{
    totalSalaries = ptrSR->getSumOfSalaries();
    totalSparePartsIn = ptrSPL->getTotalPrice(false);
    totalSparePartsOut = ptrSPL->getTotalPrice(true);
    totalServices = ptrSL->getTotalServices();

    wcout << L"Годовой отчет\n";
    wcout << L"РАСХОДЫ \n";
    wcout << L"Затраты на з.ч.: " << totalSparePartsOut << "\n";
    wcout << L"Оплаты мастерам: " << totalSalaries << "\n";
    int totalOutcome = totalSparePartsOut + totalSalaries;
    wcout << L"Итого: " << totalOutcome << "\n\n";

    wcout << L"ДОХОДЫ\n";
    wcout << L"Продажа з.ч.: " << totalSparePartsIn << "\n";
    wcout << L"Услуги: " << totalServices << "\n";
    int totalIncome = totalSparePartsIn + totalServices;
    wcout << L"Общий доход: " << totalIncome << "\n\n";

    wcout << L"Баланс: " << totalIncome - totalOutcome;


    getch();
}

void AnnualReport::updateTotalSalaries(int total)
{
    totalSalaries = total;
}
