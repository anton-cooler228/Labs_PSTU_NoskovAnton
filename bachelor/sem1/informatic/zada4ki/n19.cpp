// задача о 8 ферзях
#include <iostream>
#include <clocale>
#include <vector>

using namespace std;

const int BOARD_SIZE = 8;

// Функция проверки, можно ли поставить ферзя в позицию (row, col)
bool isSafe(const vector<int>& queens, int row, int col) 
{
    for (int i = 0; i < row; ++i) 
    {
        // Проверяем вертикаль и диагонали
        if (queens[i] == col ||
            abs(queens[i] - col) == abs(i - row)) 
            {
            return false;
        }
    }
    return true;
}

// Рекурсивная функция поиска решений
bool solveNQueens(vector<int>& queens, int row) 
{
    // Если все ферзи расставлены — нашли решение
    if (row == BOARD_SIZE) 
    {
        return true;
    }

    // Пробуем поставить ферзя в каждую клетку текущей строки
    for (int col = 0; col < BOARD_SIZE; ++col) 
    {
        if (isSafe(queens, row, col)) 
        {
            queens[row] = col;

            // Рекурсивно пытаемся расставить оставшихся ферзей
            if (solveNQueens(queens, row + 1)) 
            {
                return true;
            }
        }
    }

    return false; // Решение не найдено
}

// Функция вывода доски на консоль
void printBoard(const vector<int>& queens) 
{
    cout << "\nРешение задачи о восьми ферзях:\n\n";

    // Верхняя граница
    cout << "  +";
    for (int j = 0; j < BOARD_SIZE; ++j) 
    {
        cout << "---";
    }
    cout << "+\n";

    // Рисуем доску
    for (int i = 0; i < BOARD_SIZE; ++i) 
    {
        cout << i + 1 << " |"; // Номера строк

        for (int j = 0; j < BOARD_SIZE; ++j) 
        {
            if (queens[i] == j) 
            {
                cout << " Q "; // Ферзь
            } 
            else 
            {
                // Чередование клеток: чёрные и белые
                if ((i + j) % 2 == 0) 
                {
                    cout << " · "; // Белая клетка
                } 
                else 
                {
                    cout << " # "; // Чёрная клетка
                }
            }
        }
        cout << "|\n";
    }

    // Нижняя граница
    cout << "  +";
    for (int j = 0; j < BOARD_SIZE; ++j) 
    {
        cout << "---";
    }
    cout << "+\n  ";

    // Буквы столбцов
    for (int j = 0; j < BOARD_SIZE; ++j) 
    {
        cout << " " << char('a' + j) << " ";
    }
    cout << "\n\n";
}

int main() 
{
    setlocale(LC_ALL, ".65001");

    vector<int> queens(BOARD_SIZE, -1); // Массив позиций ферзей: индекс — строка, значение — столбец

    cout << "Поиск решения задачи о восьми ферзях...\n";

    if (solveNQueens(queens, 0)) 
    {
        printBoard(queens);
    } 
    else 
    {
        cout << "Решение не найдено!\n";
    }

    return 0;
}
