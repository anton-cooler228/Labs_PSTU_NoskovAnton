#include <windows.h>
#include <iostream>
using namespace std;

const int MAX = 20;

// Ввод массива с клавиатуры
void readArr(int a[][MAX], int n)
{
    cout << "Ввод элементов массива:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

// Минимальный элемент столбца col
int colMin(int a[][MAX], int n, int col)
{
    int m = a[0][col];
    for (int i = 1; i < n; i++)
    {
        if (a[i][col] < m)
        {
            m = a[i][col];
        }
    }
    return m;
}

// Наименьший элемент столбца col, больший x;
// если такого нет, возвращается сам x (признак неудачи)
int nextAbove(int a[][MAX], int n, int col, int x)
{
    int m = x;
    for (int i = 0; i < n; i++)
    {
        if (a[i][col] > x && (m == x || a[i][col] < m))
        {
            m = a[i][col];
        }
    }
    return m;
}

// проверка: обходим столбцы в порядке побочной диагонали
bool canDiag(int a[][MAX], int n, int diag[])
{
    int cur = colMin(a, n, n - 1);
    diag[n - 1] = cur;
    bool ok = true;
    for (int j = n - 2; j >= 0 && ok; j--)
    {
        int m = nextAbove(a, n, j, cur);
        if (m == cur)
        {
            ok = false;
        }
        else
        {
            cur = m;
            diag[j] = cur;
        }
    }
    return ok;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a[MAX][MAX];
    int diag[MAX];
    int n;
    bool ok;

    do
    {
        cout << "Размер массива N (от 1 до " << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);

    readArr(a, n);
    ok = canDiag(a, n, diag);

    if (ok)
    {
        cout << "Можно. Элементы побочной диагонали:\n";
        for (int j = n - 1; j >= 0; j--)
        {
            cout << diag[j] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Нельзя\n";
    }

    return 0;
}
