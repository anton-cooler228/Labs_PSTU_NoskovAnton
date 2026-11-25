// динамический массив - удаление и добавление
#include <iostream>
#include <cstdlib>
#include <clocale>  // для realloc, malloc, free

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    int* arr = nullptr;  // указатель на массив
    int size = 0;       // текущий размер массива
    int capacity = 0;     // текущая ёмкость (выделенная память)
    int choice, value, index;

    cout << "Программа для работы с динамическим массивом\n";

    while (true)
    {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент в конец\n";
        cout << "2. Добавить элемент по индексу\n";
        cout << "3. Удалить последний элемент\n";
        cout << "4. Удалить элемент по индексу\n";
        cout << "5. Вывести массив\n";
        cout << "6. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Введите значение: ";
                cin >> value;

                // Увеличиваем ёмкость, если нужно
                if (size >= capacity)
                {
                    capacity = (capacity == 0) ? 1 : capacity * 2;
                    arr = (int*)realloc(arr, capacity * sizeof(int));
                    if (arr == nullptr)
            {
                cout << "Ошибка выделения памяти!\n";
                return 1;
            }
        }
        arr[size++] = value;
        cout << "Элемент добавлен.\n";
        break;
    }

            case 2:
            {
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Введите значение: ";
                cin >> value;

                if (index < 0 || index > size)
                {
            cout << "Неверный индекс!\n";
            break;
        }

        // Увеличиваем ёмкость, если нужно
        if (size >= capacity)
        {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (arr == nullptr)
            {
                cout << "Ошибка выделения памяти!\n";
                return 1;
            }
        }

        // Сдвигаем элементы вправо
        for (int i = size; i > index; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
        cout << "Элемент добавлен по индексу " << index << ".\n";
        break;
    }

            case 3:
            {
                if (size == 0)
                {
            cout << "Массив пуст!\n";
        }
        else
        {
            size--;
            cout << "Последний элемент удалён.\n";
            // Опционально: уменьшаем ёмкость при малом заполнении
            if (size < capacity / 4 && capacity > 1)
            {
                capacity /= 2;
                arr = (int*)realloc(arr, capacity * sizeof(int));
                if (arr == nullptr && capacity > 0)
                {
            cout << "Предупреждение: не удалось уменьшить память.\n";
                }
            }
        }
        break;
    }

            case 4:
            {
                cout << "Введите индекс для удаления: ";
                cin >> index;

                if (index < 0 || index >= size)
                {
            cout << "Неверный индекс!\n";
            break;
        }

        // Сдвигаем элементы влево
        for (int i = index; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Элемент по индексу " << index << " удалён.\n";

        // Опционально: уменьшаем ёмкость
        if (size < capacity / 4 && capacity > 1)
        {
            capacity /= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (arr == nullptr && capacity > 0)
            {
                cout << "Предупреждение: не удалось уменьшить память.\n";
            }
        }
        break;
    }

            case 5:
            {
                cout << "Текущий массив: ";
                if (size == 0)
                {
            cout << "(пусто)";
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\nРазмер: " << size << ", ёмкость: " << capacity << "\n";
        break;
    }

            case 6:
            {
                cout << "Выход из программы.\n";
                free(arr);  // Освобождаем память
                return 0;
            }

            default:
            {
                cout << "Неверный выбор!\n";
                break;
            }
        }  // конец switch
    }  // конец while

    return 0;
}
