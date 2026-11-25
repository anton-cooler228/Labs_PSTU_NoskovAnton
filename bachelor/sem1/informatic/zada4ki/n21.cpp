// ромб не массив
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");
    int n;
    cout << "Введите нечётное n: ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) 
    {
        cout << "n должно быть положительным нечётным числом." << endl;
        return 1;
    }

    int mid = n / 2;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            int dist = abs(i - mid) + abs(j - mid);
            if (dist == mid) 
            {
                cout << 1;  // граница ромба
            } 
            else if (dist < mid) 
            {
                cout << 0;  // внутри ромба
            } 
            else 
            {
                cout << " ";  // вне ромба
            }
        }
        cout << endl;
    }

    return 0;
}
