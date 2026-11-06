#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    int n;
    cin >> n;

    if (n < 1 || n % 2 == 0) 
    {
        cout << "Некорректный ввод. n должно быть положительным нечётным числом." << endl;
    }
    else
    {
        int str = (n + 1) / 2;

        for (int i = 0; i < str; ++i) 
        {
            int p = str - 1 - i;
            for (int j = 0; j < p; ++j) 
            {
                cout << ' ';
            }
            
            int z = 2 * i + 1;
            for (int k = 0; k < z; ++k) 
            {
                cout << '*';
            }

            cout << '\n';
        }
    }

    return 0;
}
