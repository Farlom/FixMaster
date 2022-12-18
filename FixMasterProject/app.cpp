#include "fixmaster.h"
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    UserInterface UI;

    UI.start();


     return 0;
}

