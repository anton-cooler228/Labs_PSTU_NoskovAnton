// объявление функции .h
#include <iostream>
#include <clocale>
#include "sum.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a, b;

    cout << "Введите первое число: ";
    cin >> a;

    cout << "Введите второе число: ";
    cin >> b;

    sum(a, b);

    return 0;
}
