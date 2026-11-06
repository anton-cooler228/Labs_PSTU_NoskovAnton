// проверка упорядочености последовательности по возрастанию
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    int a, b;
    bool f = true;

    if (!(cin >> a) || (a == 0)) 
    {
        cout << "Последовательность пустая." << endl;
        return 0;
    }

    cin >> b;

    while ((b != 0) && f) 
    {
        if (!(a < b)) 
        {
            f = false;
        }

        a = b;
        cin >> b;
    }

    if (f) 
    {
        cout << "Последовательность упорядочена по возрастанию." << endl;
    } 
    else 
    {
        cout << "Последовательность НЕ упорядочена по возрастанию." << endl;
    }

    return 0;
}