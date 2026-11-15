#include <windows.h>
#include <iostream>
using namespace std;

// Перенос n колец: с стержня from на стержень to через via
void hanoi(int n, int from, int to, int via, int &step)
{
    if (n == 0)
    {
        return;
    }
    hanoi(n - 1, from, via, to, step);
    step++;
    cout << step << ". кольцо " << n << ": " << from << " -> " << to << "\n";
    hanoi(n - 1, via, to, from, step);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 5;
    int step = 0;

    cout << "Перенос " << n << " колец со стержня 1 на стержень 3:\n";
    hanoi(n, 1, 3, 2, step);
    cout << "Всего ходов: " << step << "\n";

    return 0;
}
