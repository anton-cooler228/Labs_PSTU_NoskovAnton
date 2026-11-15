// объявление функции до определения
#include <iostream>
#include <clocale>

using namespace std;

void sum(int, int);

int main()
{
    setlocale(LC_ALL, "RU");
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    sum(a, b);
    return 0;
}

void sum(int a, int b)
{
    cout << "Результат суммы: " << a + b << endl;
}
