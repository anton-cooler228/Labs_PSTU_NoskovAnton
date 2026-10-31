// сумма элементов 2 строк массива
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    const int ROWS = 2;
    const int COLS = 5;
    int arr[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            cin >> arr[i][j];
        }
    }

    int totalSum = 0;

    for (int i = 0; i < ROWS; ++i) 
    {
        int rowSum = 0;

        for (int j = 0; j < COLS; ++j) 
        {
            rowSum = rowSum + arr[i][j];
        }

        totalSum = totalSum + rowSum;

        cout << "Сумма элементов строки " << (i + 1) << ": " << rowSum << endl;
    }

    cout << "Общая сумма всех элементов: " << totalSum << endl;

    return 0;
}
