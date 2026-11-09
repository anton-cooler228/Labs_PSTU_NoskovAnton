#include <iostream>
#include <clocale>
using namespace std;

// Функция для вывода массива
void mas(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Сортировка вставками с флажком
void vstavka(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        bool f = false;

        while (j >= 0 && !f)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            else
            {
                f = true;
            }
        }
        arr[j + 1] = key;
    }
}

// Сортировка выбором
void vibor(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Пузырьковая сортировка
void bubble(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, ".65001");

    const int SIZE = 7;
    int arr[SIZE];
    int original[SIZE]; // Чтобы хранить исходный массив для повторных сортировок

    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr[i];
        original[i] = arr[i]; // Сохраняем копию
    }

    cout << "Исходный массив: ";
    mas(arr, SIZE);

    // 1. Сортировка вставками с флажком f
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = original[i];
    }
    vstavka(arr, SIZE);
    cout << "После сортировки вставками с флажком: ";
    mas(arr, SIZE);

    // 2. Сортировка выбором
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = original[i];
    }
    vibor(arr, SIZE);
    cout << "После сортировки выбором: ";
    mas(arr, SIZE);

    // 3. Пузырьковая сортировка без флажка
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = original[i];
    }
    bubble(arr, SIZE);
    cout << "После пузырьковой сортировки без флажка: ";
    mas(arr, SIZE);

    return 0;
}