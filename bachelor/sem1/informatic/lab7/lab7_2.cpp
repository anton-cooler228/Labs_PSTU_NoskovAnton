#include <iostream>
#include <cstdarg>
#include <cstring>
#include <clocale>

using namespace std;

// Вспомогательные функции
bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) 
{
    static const int days[] = {31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

bool parseDate(const char* dateStr, int& day, int& month, int& year) 
{
    if (strlen(dateStr) != 8 || dateStr[2] != '.' || dateStr[5] != '.') 
    {
        return false;
    }
    for (int i = 0; i < 8; i++) 
    {
        if (i != 2 && i != 5 && !isdigit(dateStr[i])) return false;
    }

    day = (dateStr[0] - '0') * 10 + (dateStr[1] - '0');
    month = (dateStr[3] - '0') * 10 + (dateStr[4] - '0');
    year = 2000 + (dateStr[6] - '0') * 10 + (dateStr[7] - '0');

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;

    return true;
}

long dateToDays(int day, int month, int year) 
{
    long days = 0;
    for (int y = 1900; y < year; y++) 
    {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) 
    {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

// Функция с переменным числом параметров — разница между соседними датами
void days(int n, ...) 
{
    va_list args;
    va_start(args, n);

    // Динамическое выделение массива указателей на даты
    const char** dates = new const char*[n];
    int d1, m1, y1, d2, m2, y2;

    // Сохраняем все даты в массив
    for (int i = 0; i < n; i++) 
    {
        dates[i] = va_arg(args, const char*);
    }
    va_end(args);

    long totalDays = 0;
    int validPairs = 0;  // счётчик корректно обработанных пар

    cout << "\n--- Разницы между соседними датами ---\n";
    for (int i = 0; i < n - 1; i++) 
    {
        // Парсим текущую и следующую дату
        if (!parseDate(dates[i], d1, m1, y1) || !parseDate(dates[i + 1], d2, m2, y2)) 
        {
            cerr << "Ошибка в дате \"" << dates[i] << "\" или \"" << dates[i + 1] << "\" — пропускаем эту пару\n";
            continue;  // пропускаем текущую пару, переходим к следующей
        }

        long days1 = dateToDays(d1, m1, y1);
        long days2 = dateToDays(d2, m2, y2);
        int diff = abs(days2 - days1);

        cout << dates[i] << " → " << dates[i + 1] << ": " << diff << " дней\n";
        totalDays += diff;
        validPairs++;
    }

    if (validPairs > 0) 
    {
        cout << "Всего периодов: " << validPairs << ", суммарно: " << totalDays << " дней\n";
    } 
    else 
    {
        cout << "Не удалось обработать ни одной пары дат из‑за ошибок.\n";
    }

    // Освобождаем выделенную память
    delete[] dates;
}


int main() 
{
    setlocale(LC_ALL, ".65001");

    const int MAX_DATES = 20;
    const int DATE_LEN = 9;

    char dates[MAX_DATES][DATE_LEN];

    cout << "Программа расчёта дней между соседними датами\n\n";

    int callParams[] = {3, 5, 8};

    for (int call = 0; call < 3; call++) 
    {
        int n = callParams[call];
        cout << "--- Вызов №" << (call + 1) << " (" << n << " дат) ---\n";
        cout << "Введите " << n << " дат в формате дд.мм.гг:\n";

        for (int i = 0; i < n; i++) 
        {
            cout << "Дата " << (i + 1) << ": ";
            cin >> dates[i];
        }

        switch (n) 
        {
            case 3:
                days(3, dates[0], dates[1], dates[2]);
                break;
            case 5:
                days(5, dates[0], dates[1], dates[2], dates[3], dates[4]);
                break;
            case 8:
                days(8, dates[0], dates[1], dates[2], dates[3],
                      dates[4], dates[5], dates[6], dates[7]);
                break;
        }
        cout << endl;
    }

    return 0;
}
