#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n, i = 1, a;
    bool f = false;

    cin >> n;

    while((i <= n) && !f) 
    {
        cin >> a;
  
        if(a != 0)
        {
            f = true;
        else
            i += 1;
        }
    }

    if(f)
    {
        if(a > 0)
        {
            cout << "a = " << a << "- Положительное\n";
        else
            cout << "a = " << a << "- Отрицательное\n";
        }
    else
        cout << "В последовательности все нули\n";
    }

    return 0;
}
