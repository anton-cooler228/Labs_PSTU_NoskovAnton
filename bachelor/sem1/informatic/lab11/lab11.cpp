#include <iostream>
#include <cstring>
#include <fstream>
#include <locale>
#include <windows.h>

using namespace std;

// Структура узла двусвязного списка
struct Node 
{
    char* key;
    Node* prev;
    Node* next;

    Node(const char* k)
    {
        key = new char[strlen(k) + 1];
        strcpy(key, k);
        prev = nullptr;
        next = nullptr;
    }

    ~Node()
    {
        delete[] key;
    }
};

// Структура списка
struct List 
{
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr) {}
};

// 1. Создание списка
void crtList(List& l)
{
    l.head = nullptr;
    l.tail = nullptr;
}

// 2. Добавление элемента в конец списка
void addEnd(List& l, const char* k)
{
    Node* n = new Node(k);
    if (l.head == nullptr) 
    {
        l.head = n;
        l.tail = n;
    } 
    else 
    {
        n->prev = l.tail;
        l.tail->next = n;
        l.tail = n;
    }
}

// 3. Удаление элемента с заданным ключом
bool remKey(List& l, const char* k)
{
    Node* curr = l.head;
    while (curr != nullptr) 
    {
        if (strcmp(curr->key, k) == 0) 
        {
            if (curr->prev != nullptr) 
            {
                curr->prev->next = curr->next;
            } 
            else 
            {
                l.head = curr->next;
            }
            if (curr->next != nullptr) 
            {
                curr->next->prev = curr->prev;
            }
            else 
            {
                l.tail = curr->prev;
            }
            delete curr;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// 4. Печать списка
void prtList(const List& l)
{
    if (l.head == nullptr) 
    {
        cout << "Список пуст." << endl;
        return;
    }
    cout << "Список: ";
    Node* curr = l.head;
    while (curr != nullptr) 
    {
        cout << curr->key;
        if (curr->next != nullptr) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
}

// 5. Запись списка в файл
void saveF(const List& l, const char* fn)
{
    ofstream f(fn);
    if (!f.is_open()) 
    {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    Node* curr = l.head;
    while (curr != nullptr) 
    {
        f << curr->key << endl;
        curr = curr->next;
    }
    f.close();
    cout << "Список сохранён в файл: " << fn << endl;
}

// 6. Уничтожение списка
void destL(List& l)
{
    Node* curr = l.head;
    while (curr != nullptr)
    {
        Node* nx = curr->next;
        delete curr;
        curr = nx;
    }
    l.head = nullptr;
    l.tail = nullptr;
}

// 7. Восстановление списка из файла
bool loadF(List& l, const char* fn)
{
    ifstream f(fn);
    if (!f.is_open()) 
    {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return false;
    }
    char buf[256];
    while (f.getline(buf, sizeof(buf))) 
    {
        addEnd(l, buf);
    }
    f.close();
    cout << "Список восстановлен из файла: " << fn << endl;
    return true;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".65001");

    List lst;
    crtList(lst);

    int choice;
    char input[256];

    do 
    {
        cout << "\n--- Меню ---" << endl;
        cout << "1. Добавить элемент в конец списка" << endl;
        cout << "2. Удалить элемент по ключу" << endl;
        cout << "3. Показать список" << endl;
        cout << "4. Сохранить список в файл" << endl;
        cout << "5. Загрузить список из файла" << endl;
        cout << "6. Уничтожить список" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        
        if (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод. Попробуйте снова." << endl;
            continue;
        }
        cin.ignore(); // Очищаем буфер после чтения числа

        switch (choice) 
        {
            case 1:
                cout << "Введите строку для добавления: ";
                cin.getline(input, sizeof(input));
                if (input[0] == '\0') 
                {
                    cout << "Пустая строка не добавлена." << endl;
                } 
                else 
                {
                    addEnd(lst, input);
                    cout << "Элемент добавлен." << endl;
                }
                break;

            case 2:
                cout << "Введите ключ для удаления: ";
                cin.getline(input, sizeof(input));
                if (remKey(lst, input)) 
                {
                    cout << "Элемент удалён." << endl;
                } 
                else 
                {
                    cout << "Элемент с таким ключом не найден." << endl;
                }
                break;

            case 3:
                prtList(lst);
                break;

            case 4:
                cout << "Введите имя файла для сохранения: ";
                cin.getline(input, sizeof(input));
                if (input[0] != '\0') 
                {
                    saveF(lst, input);
                } 
                else 
                {
                    cout << "Имя файла не введено." << endl;
                }
                break;

            case 5:
                cout << "Введите имя файла для загрузки: ";
                cin.getline(input, sizeof(input));
                if (input[0] != '\0') 
                {
                    destL(lst);          // Сначала очищаем текущий список
                    loadF(lst, input);   // Потом загружаем из файла
                } 
                else 
                {
                    cout << "Имя файла не введено." << endl;
                }
                break;

            case 6:
                destL(lst);
                cout << "Список уничтожен." << endl;
                break;

            case 0:
                cout << "Выход из программы." << endl;
                break;

            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    destL(lst); // Гарантированное освобождение памяти при выходе
    return 0;
}
