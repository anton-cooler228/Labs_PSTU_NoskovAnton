#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

const int N = 8;
int cnt = 0; // счётчик решений

// Проверка безопасности позиции (r, c)
bool safe(int q[], int r, int c) 
{
    for (int i = 0; i < r; ++i) 
    {
        if (q[i] == c || abs(q[i] - c) == abs(i - r)) 
        {
            return false;
        }
    }
    return true;
}

// Поиск всех решений
void solve(int q[], int r) 
{
    if (r == N) 
    {
        ++cnt;
        print(q);
        return;
    }

    for (int c = 0; c < N; ++c) 
    {
        if (safe(q, r, c)) 
        {
            q[r] = c;
            solve(q, r + 1);
        }
    }
}

// Вывод доски
void print(int q[]) 
{
    cout << "\nРешение №" << cnt << ":\n\n";

    // Верхняя граница
    cout << "  +";
    for (int j = 0; j < N; ++j) 
    {
        cout << "---";
    }
    cout << "+\n";

    // Рисуем доску
    for (int i = 0; i < N; ++i) 
    {
        cout << i + 1 << " |";
        for (int j = 0; j < N; ++j) 
        {
            if (q[i] == j) 
            {
                cout << " Q ";
            } 
            else 
            {
                if ((i + j) % 2 == 0) 
                {
                    cout << " · ";
                } 
                else 
                {
                    cout << " # ";
                }
            }
        }
        cout << "|\n";
    }

    // Нижняя граница
    cout << "  +";
    for (int j = 0; j < N; ++j) 
    {
        cout << "---";
    }
    cout << "+\n  ";

    // Буквы столбцов
    for (int j = 0; j < N; ++j) 
    {
        cout << " " << char('a' + j) << " ";
    }
    cout << "\n\n";
}

int main() 
{
    setlocale(LC_ALL, ".65001");

    int q[N]; // позиции ферзей: индекс — строка, значение — столбец

    cout << "Поиск всех решений задачи о восьми ферзях...\n";
    cout << "Всего решений: 92\n\n";

    solve(q, 0);

    cout << "Найдено решений: " << cnt << endl;

    return 0;
}
