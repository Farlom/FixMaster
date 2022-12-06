#include "fixmaster.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Master* test = new Master("IMYA", 12300);
    cout<<test->getName();
    cout<<test->getSalary();

     return 0;
}

