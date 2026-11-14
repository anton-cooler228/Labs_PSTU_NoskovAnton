#include <clocale>
#include <iostream>
using namespace std;

// а) часы и минуты -> минуты
int time(int h, int m)
{
    return h * 60 + m;
}

// б) минуты -> часы и минуты (через ссылки)
void time(int total, int &h, int &m)
{
    h = total / 60;
    m = total % 60;
}

int main()
{
    setlocale(LC_ALL, ".65001");

    int h;
    int m;
    int total;

    cout << "Ввод - часы и минуты: ";
    cin >> h >> m;
    total = time(h, m);
    cout << "Всего минут: " << total << "\n";

    cout << "Ввод - количество минут: ";
    cin >> total;
    time(total, h, m);
    cout << "Это " << h << " ч. " << m << " мин.\n";

    return 0;
}
