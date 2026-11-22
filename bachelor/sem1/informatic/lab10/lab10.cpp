#include <iostream>
#include <clocale>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    cout << "Сколько строк ввести? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Число строк должно быть больше 0.\n";
        return 0;
    }

    // Динамический массив указателей на строки
    char** arr = new char*[n];
    const int MAX_LEN = 256;

    for (int i = 0; i < n; ++i)
    {
        arr[i] = new char[MAX_LEN];
        cin.ignore(); // убрать остаток буфера после числа
        cout << "Строка " << i + 1 << ": ";
        cin.getline(arr[i], MAX_LEN);
    }

    // Ищем индекс самой короткой строки
    int minIdx = 0;
    size_t minLen = strlen(arr[0]);

    for (int i = 1; i < n; ++i)
    {
        size_t curLen = strlen(arr[i]);
        if (curLen < minLen)
        {
            minLen = curLen;
            minIdx = i;
        }
    }

    // Создаём новый массив без самой короткой строки (размер n-1)
    char** res = new char*[n - 1];
    int idx = 0; // индекс в новом массиве

    for (int i = 0; i < n; ++i)
    {
        if (i == minIdx)
        {
            continue; // пропускаем самую короткую
        }
        res[idx] = new char[MAX_LEN];
        strcpy(res[idx], arr[i]);
        ++idx;
    }

    // Выводим результат
    cout << "\nМассив после удаления самой короткой строки:\n";
    for (int i = 0; i < n - 1; ++i)
    {
        cout << res[i] << "\n";
    }

    // Освобождаем память
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0; i < n - 1; ++i)
    {
        delete[] res[i];
    }
    delete[] res;

    return 0;
}
