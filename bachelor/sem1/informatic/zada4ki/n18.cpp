// задача про 2-мерную матрицу и нули
#include <iostream>
#include <clocale>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    cout << "Ввод размер матрицы n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Размер должен быть положительным числом." << endl;
        return 0;
    }

    // Создаём матрицу n×n, заполненную нулями
    vector<vector<int>> mat(n, vector<int>(n, 0));

    // Вводим число, которое будет стоять на позициях «x»
    int x;
    cout << "Ввод числа для позиций «x»: ";
    cin >> x;

    // Заполняем матрицу по шаблону
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            // Первая строка: x в первом и последнем столбце
            mat[i][0] = x;
            if (n > 1)
            {
                mat[i][n - 1] = x;
            }
        }
        else if (i == 1)
        {
            // Вторая строка: x в первых двух и последних двух столбцах
            for (int j = 0; j < 2; ++j)
            {
                mat[i][j] = x;
            }
            for (int j = n - 2; j < n; ++j)
            {
                if (j >= 0 && j < n)
                {
                    mat[i][j] = x;
                }
            }
        }
        else
        {
            // Остальные строки: вся строка заполняется x
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = x;
            }
        }
    }

    // Выводим итоговую матрицу
    cout << "\nИтоговая матрица:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}