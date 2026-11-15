#include "sum.h"
#include <iostream>
#include <clocale>

using namespace std;

void sum(int a, int b)
{
    setlocale(LC_ALL, ".65001");
    cout << "Результат суммы: " << a + b << endl;
}
