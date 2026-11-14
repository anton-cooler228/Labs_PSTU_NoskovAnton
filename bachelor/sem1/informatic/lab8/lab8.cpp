#include <clocale>
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>  // для SetConsoleCP/OutputCP
using namespace std;

const int FLEN = 60;
const int CLEN = 12;
const int PLEN = 15;
const int TLEN = 10;
const int MAX = 100;

struct Owner 
{
    char fio[FLEN];
    char car[CLEN];
    char phone[PLEN];
    char tech[TLEN];
};

const char NAME[] = "owners.dat";

// Сравнение двух строк
bool sameStr(char a[], char b[]) 
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) 
    {
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

// Ввод одной записи с клавиатуры
void inputOwner(Owner &o) 
{
    cout << "  ФИО: ";
    cin.getline(o.fio, FLEN);
    cout << "  Номер автомобиля: ";
    cin.getline(o.car, CLEN);
    cout << "  Телефон: ";
    cin.getline(o.phone, PLEN);
    cout << "  Номер техпаспорта: ";
    cin.getline(o.tech, TLEN);
}

// Формирование двоичного файла
void makeFile(Owner a[], int num) 
{
    ofstream f(NAME, ios::binary);
    if (!f) 
    {
        cout << "Ошибка открытия файла для записи\n";
        return;
    }

    bool ok = true;
    for (int i = 0; i < num && ok; i++) 
    {
        if (!f.write((char*)&a[i], sizeof(Owner))) 
        {
            cout << "Ошибка записи в файл на позиции " << i << "\n";
            ok = false;
        }
    }
    f.close();

    if (ok) 
    {
        cout << "Файл успешно создан, записано " << num << " записей\n";
    }
}

// Печать содержимого файла
void printFile() 
{
    ifstream f(NAME, ios::binary);
    if (!f) 
    {
        cout << "Ошибка открытия файла для чтения\n";
        return;
    }

    Owner o;
    int num = 0;
    cout << "\n----- Содержимое файла -----\n";

    while (f.read((char*)&o, sizeof(Owner))) 
    {
        num++;
        cout << num << ". " << o.fio << ", авто " << o.car
             << ", тел. " << o.phone << ", техпаспорт " << o.tech << "\n";
    }

    if (f.bad()) 
    {
        cout << "Ошибка чтения из файла\n";
    } 
    else if (num == 0) 
    {
        cout << "Файл пуст\n";
    } 
    else 
    {
        cout << "Всего записей: " << num << "\n";
    }
    f.close();
}

// Загрузка всех записей в массив; возвращает число записей
int loadFile(Owner a[]) 
{
    ifstream f(NAME, ios::binary);
    int num = 0;

    if (!f) 
    {
        cout << "Ошибка открытия файла для чтения\n";
        return 0;
    }

    while (num < MAX && f.read((char*)&a[num], sizeof(Owner))) 
    {
        num++;
    }

    if (f.bad()) 
    {
        cout << "Ошибка чтения из файла\n";
        num = 0;
    }
    f.close();
    return num;
}

// Сохранение массива в файл
void saveFile(Owner a[], int num) 
{
    ofstream f(NAME, ios::binary);
    if (!f) 
    {
        cout << "Ошибка открытия файла для записи\n";
        return;
    }

    bool ok = true;
    for (int i = 0; i < num && ok; i++) 
    {
        if (!f.write((char*)&a[i], sizeof(Owner))) 
        {
            cout << "Ошибка записи в файл на позиции " << i << "\n";
            ok = false;
        }
    }
    f.close();

    if (ok) 
    {
        cout << "Файл успешно сохранён, записано " << num << " записей\n";
    }
}

// Поиск записи по номеру техпаспорта; возвращает индекс или -1
int findByTech(Owner a[], int num, char tech[]) 
{
    for (int i = 0; i < num; i++) 
    {
        if (sameStr(a[i].tech, tech)) 
        {
            return i;
        }
    }
    return -1;
}

// Поиск записи по фамилии (первому слову ФИО); возвращает индекс или -1
int findByFio(Owner a[], int num, char sur[]) {
    for (int i = 0; i < num; i++) 
    {
        char w[FLEN];
        int k = 0;
        while (a[i].fio[k] != '\0' && a[i].fio[k] != ' ') 
        {
            w[k] = a[i].fio[k];
            k++;
        }
        w[k] = '\0';
        if (sameStr(w, sur)) 
        {
            return i;
        }
    }
    return -1;
}

// Удаление записи с индексом idx
void removeAt(Owner a[], int &num, int idx) {
    if (idx < 0 || idx >= num) 
    {
        cout << "Некорректный индекс для удаления\n";
        return;
    }

    for (int i = idx; i < num - 1; i++) 
    {
        a[i] = a[i + 1];
    }
    num--;
    cout << "Запись успешно удалена\n";
}

// Добавление двух записей перед элементом с заданной фамилией
void addBeforeFio(Owner a[], int &num, char sur[], Owner newOwners[2]) {
    int idx = findByFio(a, num, sur);
    if (idx < 0) 
    {
        cout << "Владелец с фамилией '" << sur << "' не найден\n";
        return;
    }

    if (num + 2 > MAX) 
    {
        cout << "Недостаточно места в массиве для добавления записей\n";
        return;
    }

    // Сдвигаем элементы вправо на 2 позиции
    for (int i = num - 1; i >= idx; i--) 
    {
        a[i + 2] = a[i];
    }

    // Вставляем новые записи
    a[idx] = newOwners[0];
    a[idx + 1] = newOwners[1];
    num += 2;
    cout << "Две записи успешно добавлены перед владельцем с фамилией '" << sur << "'\n";
}

int main() 
{
    // Переключаем консоль на UTF-8
    system("chcp 65001 > nul");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".65001");

    Owner a[MAX];
    Owner nw[2];
    char tech[TLEN];
    char sur[FLEN];
    int num;
    int idx;

    // Формирование файла
    cout << "Формирование файла владельцев автомобилей:\n";
    cout << "Число владельцев: ";
    cin >> num;

    if (num < 1 || num > MAX) 
    {
        cout << "Некорректное количество записей. Устанавливаю " << MAX << "\n";
        num = MAX;
    }

    // Двойная очистка буфера
    cin.ignore(1, '\n');
    cin.clear();

    for (int i = 0; i < num; i++) 
    {
        cout << "Владелец " << i + 1 << ":\n";
        inputOwner(a[i]);
    }

    makeFile(a, num);
    printFile();

    // Удаление элемента по номеру техпаспорта
    cout << "\nУдаление элемента:\n";
    cout << "Введите номер техпаспорта для удаления: ";
    cin.getline(tech, TLEN);

    num = loadFile(a);
    idx = findByTech(a, num, tech);

    if (idx < 0) 
    {
        cout << "Владелец с номером техпаспорта '" << tech << "' не найден\n";
    } 
    else 
    {
        removeAt(a, num, idx);
        saveFile(a, num);
        printFile();
    }

    // Добавление двух элементов перед заданной фамилией
    cout << "\nДобавление элементов:\n";
    cout << "Введите фамилию, перед которой нужно добавить записи: ";
    cin.getline(sur, FLEN);

    num = loadFile(a);

    cout << "Введите данные для двух новых владельцев:\n";
    for (int i = 0; i < 2; i++) 
    {
        cout << "Новый владелец " << i + 1 << ":\n";
        inputOwner(nw[i]);
    }

    addBeforeFio(a, num, sur, nw);
    saveFile(a, num);
    printFile();

    return 0;
}
