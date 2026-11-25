// ромб массив
#include <iostream>
#include <cmath>
#include <clocale>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    int n;

    cout << "Введите размер матрицы n (нечётное): ";
    cin >> n;

    if (n <= 0 || n % 2 == 0)
    {
        cout << "n должно быть положительным нечётным числом." << endl;
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    // Создание динамического двумерного массива n×n
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    // Заполнение массива случайными числами (от 0 до 9)
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int mid = n / 2;

    // Вывод итогового узора (ромба)
    cout << "\nРезультат (ромб на основе массива):" << endl;
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
                // ВНЕ РОМБА — выводим исходное значение из массива
                cout << matrix[i][j];
            }
        }
        cout << endl;  // переход на новую строку
    }

    // Освобождение памяти
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
