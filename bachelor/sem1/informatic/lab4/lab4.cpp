#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    const int CAPACITY = 10;
    int arr[CAPACITY];
    
    int front = 0;
    int rear = -1;

    int choice;
    int value;
    bool running = true;

    cout << "Очередь на массиве. Доступные операции:" << endl;
    cout << "1 — Добавить элемент" << endl;
    cout << "2 — Удалить элемент" << endl;
    cout << "0 — Выход" << endl;

    while (running) 
    {
        cout << "\nВыберите операцию: ";
        cin >> choice;

        if (choice == 0) 
        {
            cout << "Выход из программы." << endl;
            if (front > rear) 
            {
                cout << "Итоговое состояние очереди: очередь пуста." << endl;
            } 
            else 
            {
                cout << "Итоговое состояние очереди: ";
                for (int i = front; i <= rear; ++i) 
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            running = false;
        }
        else if (choice == 1) 
        {
            if (rear == CAPACITY - 1) 
            {
                cout << "Ошибка: очередь переполнена, нельзя добавить элемент." << endl;
            } 
            else 
            {
                cout << "Введите значение для добавления: ";
                cin >> value;
                rear = rear + 1;
                arr[rear] = value;
                cout << "Элемент " << value << " добавлен." << endl;
            }

            // Печать очереди после попытки добавления
            if (front > rear) 
            {
                cout << "Текущее состояние очереди: очередь пуста." << endl;
            } 
            else 
            {
                cout << "Текущее состояние очереди: ";
                for (int i = front; i <= rear; ++i) 
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 2) 
        {
            if (front > rear) 
            {
                cout << "Ошибка: очередь пуста, нечего удалять." << endl;
            } 
            else 
            {
                int removed = arr[front];
                front = front + 1;
                cout << "Удален элемент: " << removed << endl;
            }

            // Печать очереди после попытки удаления
            if (front > rear) 
            {
                cout << "Текущее состояние очереди: очередь пуста." << endl;
            } 
            else 
            {
                cout << "Текущее состояние очереди: ";
                for (int i = front; i <= rear; ++i) 
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
        else 
        {
            cout << "Неверная операция. Выберите 0–2." << endl;

            // Даже при неверной команде печатаем текущее состояние
            if (front > rear) 
            {
                cout << "Текущее состояние очереди: очередь пуста." << endl;
            } 
            else 
            {
                cout << "Текущее состояние очереди: ";
                for (int i = front; i <= rear; ++i) 
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
