#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstring>
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
    while (a[i] != '\0' && a[i] == b[i])
    {
        i++;
    }
    return a[i] == b[i];
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
    }
    else
    {
        bool ok = true;
        for (int i = 0; i < num && ok; i++)
        {
            if (!f.write((char*)&a[i], sizeof(Owner)))
            {
                cout << "Ошибка записи в файл\n";
                ok = false;
            }
        }
        f.close();
    }
}

// Печать содержимого файла
void printFile()
{
    ifstream f(NAME, ios::binary);
    if (!f)
    {
        cout << "Ошибка открытия файла для чтения\n";
    }
    else
    {
        Owner o;
        int num = 0;
        cout << "----- Содержимое файла -----\n";
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
        if (num == 0)
        {
            cout << "Файл пуст\n";
        }
        f.close();
    }
}

// Загрузка всех записей в массив; возвращает число записей
int loadFile(Owner a[])
{
    ifstream f(NAME, ios::binary);
    int num = 0;
    if (!f)
    {
        cout << "Ошибка открытия файла для чтения\n";
    }
    else
    {
        while (num < MAX && f.read((char*)&a[num], sizeof(Owner)))
        {
            num++;
        }
        if (f.bad())
        {
            cout << "Ошибка чтения из файла\n";
        }
        f.close();
    }
    return num;
}

// Сохранение массива в файл
void saveFile(Owner a[], int num)
{
    ofstream f(NAME, ios::binary);
    if (!f)
    {
        cout << "Ошибка открытия файла для записи\n";
    }
    else
    {
        bool ok = true;
        for (int i = 0; i < num && ok; i++)
        {
            if (!f.write((char*)&a[i], sizeof(Owner)))
            {
                cout << "Ошибка записи в файл\n";
                ok = false;
            }
        }
        f.close();
    }
}

// Поиск записи по номеру техпаспорта; возвращает индекс или -1
int findByTech(Owner a[], int num, char tech[])
{
    int idx = -1;
    for (int i = 0; i < num && idx < 0; i++)
    {
        if (sameStr(a[i].tech, tech))
        {
            idx = i;
        }
    }
    return idx;
}

// Поиск записи по фамилии (первому слову ФИО); возвращает индекс или -1
int findByFio(Owner a[], int num, char sur[])
{
    int idx = -1;
    for (int i = 0; i < num && idx < 0; i++)
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
            idx = i;
        }
    }
    return idx;
}

// Удаление записи с индексом idx
void removeAt(Owner a[], int &num, int idx)
{
    for (int i = idx; i < num - 1; i++)
    {
        a[i] = a[i + 1];
    }
    num--;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Owner a[MAX];
    Owner nw[2];
    char tech[TLEN];
    char sur[FLEN];
    int num;
    int idx;

    cout << "Число владельцев: ";
    cin >> num;
    if (num < 1 || num > MAX)
    {
        num = MAX;
    }
    cin.ignore();
    for (int i = 0; i < num; i++)
    {
        cout << "Владелец " << i + 1 << ":\n";
        inputOwner(a[i]);
    }
    makeFile(a, num);
    printFile();

    cout << "Номер техпаспорта для удаления: ";
    cin.getline(tech, TLEN);
    num = loadFile(a);
    idx = findByTech(a, num, tech);
    if (idx < 0)
    {
        cout << "Запись с таким номером техпаспорта не найдена\n";
    }
    else
    {
        removeAt(a, num, idx);
        saveFile(a, num);
        cout << "Запись удалена\n";
        printFile();
    }

    cout << "Фамилия, перед которой добавить записи: ";
    cin.getline(sur, FLEN);
    num = loadFile(a);
    idx = findByFio(a, num, sur);
    if (idx < 0)
    {
        cout << "Запись с такой фамилией не найдена\n";
    }
    else if (num + 2 > MAX)
    {
        cout << "В массиве нет места для добавления\n";
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            cout << "Новый владелец " << i + 1 << ":\n";
            inputOwner(nw[i]);
        }
        for (int i = num - 1; i >= idx; i--)
        {
            a[i + 2] = a[i];
        }
        a[idx] = nw[0];
        a[idx + 1] = nw[1];
        num += 2;
        saveFile(a, num);
        cout << "Записи добавлены\n";
        printFile();
    }

    return 0;
}
