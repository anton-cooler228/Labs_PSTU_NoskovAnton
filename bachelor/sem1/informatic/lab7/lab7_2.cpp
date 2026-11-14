#include <clocale>
#include <iostream>
#include <cstdarg>
using namespace std;

const int MLEN = 9;

// Разбор даты из строки "дд.мм.гг" в номер дня от начала отсчёта
int toDate(char s[])
{
    int d = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int y = 2000 + (s[6] - '0') * 10 + (s[7] - '0');

    int len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        len[1] = 29;
    }

    int num = y * 365 + y / 4 - y / 100 + y / 400;
    for (int i = 0; i < m - 1; i++)
    {
        num += len[i];
    }
    return num + d;
}

// функция с переменным числом параметров:
// n — количество дат, далее даты в формате "дд.мм.гг"
int days(int n, ...)
{
    va_list p;
    va_start(p, n);

    int first = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int num = toDate(va_arg(p, char*));
        if (i == 0)
        {
            first = num;
        }
        last = num;
    }
    va_end(p);

    if (last < first)
    {
        int t = first;
        first = last;
        last = t;
    }
    return last - first;
}

int main()
{
    setlocale(LC_ALL, ".65001");

    cout << "3 параметра (2 даты): " << days(2, "01.03.26", "10.03.26") << " дн.\n";
    cout << "5 параметров (4 даты): " << days(4, "01.01.26", "01.02.26", "01.03.26", "15.03.26") << " дн.\n";
    cout << "8 параметров (7 дат): " << days(7, "25.12.26", "26.12.26", "27.12.26", "28.12.26", "29.12.26", "30.12.25", "01.01.24") << " дн.\n";

    return 0;
}
