// построение квадрата
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    int n;
    cin >> n;
    if (n < 1) 
    {
        cout << "Некорректный ввод. n должно быть положительным числом." << endl;
    }
    else
    {
        // Первая строка
        for (int i = 0; i < n; ++i) 
        {
            cout << '*';
        }
        cout << '\n';

        // Средние строки
        for (int i = 0; i < n - 2; ++i) 
        {
            cout << '*';
            for (i = 0; i < n - 2; ++i) 
            {
                cout << ' ';
            }

            cout << "*\n";               // правый край
        }

        // Последняя строка
        if (n > 1) 
        {
            for (int i = 0; i < n; ++i) 
            {
                cout << '*';
            }
            cout << '\n';
        }
    }
    return 0;
}