#include <iostream>
#include <cstring>
#include <cstdio>
#include <locale>
#include <windows.h>

using namespace std;

// ==================== ОДНОСВЯЗНЫЙ СПИСОК ====================

struct SNode
{
    char* key;
    SNode* next;

    SNode(const char* k)
    {
        key = new char[strlen(k) + 1];
        strcpy(key, k);
        next = nullptr;
    }

    ~SNode()
    {
        delete[] key;
    }
};

struct SList
{
    SNode* head;

    SList()
    {
        head = nullptr;
    }
};

void sClr(SList& l)
{
    SNode* c = l.head;
    while (c != nullptr)
    {
        SNode* nx = c->next;
        delete c;
        c = nx;
    }
    l.head = nullptr;
}

int sSize(const SList& l)
{
    int sz = 0;
    for (SNode* c = l.head; c != nullptr; c = c->next)
    {
        ++sz;
    }
    return sz;
}

SNode* sGet(const SList& l, int idx)
{
    if (idx < 0)
    {
        return nullptr;
    }
    SNode* c = l.head;
    for (int i = 0; i < idx && c != nullptr; ++i)
    {
        c = c->next;
    }
    return c;
}

void sAddH(SList& l, const char* k)
{
    SNode* n = new SNode(k);
    n->next = l.head;
    l.head = n;
}

void sAddT(SList& l, const char* k)
{
    SNode* n = new SNode(k);
    if (l.head == nullptr)
    {
        l.head = n;
        return;
    }
    SNode* c = l.head;
    while (c->next != nullptr)
    {
        c = c->next;
    }
    c->next = n;
}

bool sAddI(SList& l, const char* k, int idx)
{
    int sz = sSize(l);
    if (idx < 0 || idx > sz)
    {
        return false;
    }
    if (idx == 0)
    {
        sAddH(l, k);
        return true;
    }
    SNode* p = sGet(l, idx - 1);
    if (p == nullptr)
    {
        return false;
    }
    SNode* n = new SNode(k);
    n->next = p->next;
    p->next = n;
    return true;
}

bool sAddB(SList& l, const char* val, const char* k)
{
    if (l.head == nullptr)
    {
        return false;
    }
    if (strcmp(l.head->key, val) == 0)
    {
        sAddH(l, k);
        return true;
    }
    for (SNode* c = l.head; c->next != nullptr; c = c->next)
    {
        if (strcmp(c->next->key, val) == 0)
        {
            SNode* n = new SNode(k);
            n->next = c->next;
            c->next = n;
            return true;
        }
    }
    return false;
}

bool sAddA(SList& l, const char* val, const char* k)
{
    for (SNode* c = l.head; c != nullptr; c = c->next)
    {
        if (strcmp(c->key, val) == 0)
        {
            SNode* n = new SNode(k);
            n->next = c->next;
            c->next = n;
            return true;
        }
    }
    return false;
}

bool sDelI(SList& l, int idx)
{
    int sz = sSize(l);
    if (idx < 0 || idx >= sz)
    {
        return false;
    }
    if (idx == 0)
    {
        SNode* t = l.head;
        l.head = t->next;
        delete t;
        return true;
    }
    SNode* p = sGet(l, idx - 1);
    if (p == nullptr || p->next == nullptr)
    {
        return false;
    }
    SNode* t = p->next;
    p->next = t->next;
    delete t;
    return true;
}

bool sDelK(SList& l, int idx, int k)
{
    int done = 0;
    for (int i = 0; i < k; ++i)
    {
        if (!sDelI(l, idx))
        {
            break;
        }
        ++done;
    }
    return done == k;
}

bool sAddKI(SList& l, int idx, int k, const char* base)
{
    for (int i = 0; i < k; ++i)
    {
        char tmp[64];
        sprintf(tmp, "%s%d", base, i + 1);
        if (!sAddI(l, tmp, idx + i))
        {
            return false;
        }
    }
    return true;
}

void sSort(SList& l, int dir)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    SNode* sorted = nullptr;
    SNode* c = l.head;
    while (c != nullptr)
    {
        SNode* nx = c->next;
        if (sorted == nullptr || dir * strcmp(c->key, sorted->key) <= 0)
        {
            c->next = sorted;
            sorted = c;
        }
        else
        {
            SNode* p = sorted;
            while (p->next != nullptr && dir * strcmp(p->next->key, c->key) < 0)
            {
                p = p->next;
            }
            c->next = p->next;
            p->next = c;
        }
        c = nx;
    }
    l.head = sorted;
}

void sDbl(SList& l)
{
    SNode* c = l.head;
    while (c != nullptr)
    {
        SNode* dup = new SNode(c->key);
        dup->next = c->next;
        c->next = dup;
        c = dup->next;
    }
}

void sPrint(const SList& l)
{
    cout << "Односвязный: ";
    for (SNode* c = l.head; c != nullptr; c = c->next)
    {
        cout << c->key;
        if (c->next != nullptr)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}

// ==================== ДВУСВЯЗНЫЙ СПИСОК ====================

struct DNode
{
    char* key;
    DNode* prev;
    DNode* next;

    DNode(const char* k)
    {
        key = new char[strlen(k) + 1];
        strcpy(key, k);
        prev = nullptr;
        next = nullptr;
    }

    ~DNode()
    {
        delete[] key;
    }
};

struct DList
{
    DNode* head;
    DNode* tail;

    DList()
    {
        head = nullptr;
        tail = nullptr;
    }
};

void dClr(DList& l)
{
    DNode* c = l.head;
    while (c != nullptr)
    {
        DNode* nx = c->next;
        delete c;
        c = nx;
    }
    l.head = nullptr;
    l.tail = nullptr;
}

int dSize(const DList& l)
{
    int sz = 0;
    for (DNode* c = l.head; c != nullptr; c = c->next)
    {
        ++sz;
    }
    return sz;
}

DNode* dGet(const DList& l, int idx)
{
    if (idx < 0)
    {
        return nullptr;
    }
    DNode* c = l.head;
    for (int i = 0; i < idx && c != nullptr; ++i)
    {
        c = c->next;
    }
    return c;
}

void dAddH(DList& l, const char* k)
{
    DNode* n = new DNode(k);
    if (l.head == nullptr)
    {
        l.head = n;
        l.tail = n;
        return;
    }
    n->next = l.head;
    l.head->prev = n;
    l.head = n;
}

void dAddT(DList& l, const char* k)
{
    DNode* n = new DNode(k);
    if (l.head == nullptr)
    {
        l.head = n;
        l.tail = n;
        return;
    }
    n->prev = l.tail;
    l.tail->next = n;
    l.tail = n;
}

bool dAddI(DList& l, const char* k, int idx)
{
    int sz = dSize(l);
    if (idx < 0 || idx > sz)
    {
        return false;
    }
    if (idx == 0)
    {
        dAddH(l, k);
        return true;
    }
    if (idx == sz)
    {
        dAddT(l, k);
        return true;
    }
    DNode* at = dGet(l, idx);
    DNode* n = new DNode(k);
    n->prev = at->prev;
    n->next = at;
    at->prev->next = n;
    at->prev = n;
    return true;
}

bool dAddB(DList& l, const char* val, const char* k)
{
    if (l.head == nullptr)
    {
        return false;
    }
    if (strcmp(l.head->key, val) == 0)
    {
        dAddH(l, k);
        return true;
    }
    DNode* c = l.head;
    while (c != nullptr && strcmp(c->key, val) != 0)
    {
        c = c->next;
    }
    if (c == nullptr)
    {
        return false;
    }
    DNode* n = new DNode(k);
    n->prev = c->prev;
    n->next = c;
    c->prev->next = n;
    c->prev = n;
    return true;
}

bool dAddA(DList& l, const char* val, const char* k)
{
    DNode* c = l.head;
    while (c != nullptr && strcmp(c->key, val) != 0)
    {
        c = c->next;
    }
    if (c == nullptr)
    {
        return false;
    }
    DNode* n = new DNode(k);
    n->prev = c;
    n->next = c->next;
    if (c->next != nullptr)
    {
        c->next->prev = n;
    }
    else
    {
        l.tail = n;
    }
    c->next = n;
    return true;
}

bool dDelI(DList& l, int idx)
{
    int sz = dSize(l);
    if (idx < 0 || idx >= sz)
    {
        return false;
    }
    DNode* t = dGet(l, idx);
    if (t == nullptr)
    {
        return false;
    }
    if (t->prev != nullptr)
    {
        t->prev->next = t->next;
    }
    else
    {
        l.head = t->next;
    }
    if (t->next != nullptr)
    {
        t->next->prev = t->prev;
    }
    else
    {
        l.tail = t->prev;
    }
    delete t;
    return true;
}

bool dDelK(DList& l, int idx, int k)
{
    int done = 0;
    for (int i = 0; i < k; ++i)
    {
        if (!dDelI(l, idx))
        {
            break;
        }
        ++done;
    }
    return done == k;
}

bool dAddKI(DList& l, int idx, int k, const char* base)
{
    for (int i = 0; i < k; ++i)
    {
        char tmp[64];
        sprintf(tmp, "%s%d", base, i + 1);
        if (!dAddI(l, tmp, idx + i))
        {
            return false;
        }
    }
    return true;
}

void dSort(DList& l, int dir)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    DNode* sorted = nullptr;
    DNode* c = l.head;
    while (c != nullptr)
    {
        DNode* nx = c->next;
        c->prev = nullptr;
        c->next = nullptr;
        if (sorted == nullptr || dir * strcmp(c->key, sorted->key) <= 0)
        {
            c->next = sorted;
            if (sorted != nullptr)
            {
                sorted->prev = c;
            }
            sorted = c;
        }
        else
        {
            DNode* p = sorted;
            while (p->next != nullptr && dir * strcmp(p->next->key, c->key) < 0)
            {
                p = p->next;
            }
            c->next = p->next;
            c->prev = p;
            if (p->next != nullptr)
            {
                p->next->prev = c;
            }
            p->next = c;
        }
        c = nx;
    }
    l.head = sorted;
    l.tail = sorted;
    while (l.tail->next != nullptr)
    {
        l.tail = l.tail->next;
    }
}

void dDbl(DList& l)
{
    DNode* c = l.head;
    while (c != nullptr)
    {
        DNode* dup = new DNode(c->key);
        dup->prev = c;
        dup->next = c->next;
        if (c->next != nullptr)
        {
            c->next->prev = dup;
        }
        else
        {
            l.tail = dup;
        }
        c->next = dup;
        c = dup->next;
    }
}

void dPrint(const DList& l)
{
    cout << "Двусвязный (прямой ход): ";
    for (DNode* c = l.head; c != nullptr; c = c->next)
    {
        cout << c->key;
        if (c->next != nullptr)
        {
            cout << " <-> ";
        }
    }
    cout << endl;
}

void dPrintRev(const DList& l)
{
    cout << "Двусвязный (обратный ход): ";
    for (DNode* c = l.tail; c != nullptr; c = c->prev)
    {
        cout << c->key;
        if (c->prev != nullptr)
        {
            cout << " <-> ";
        }
    }
    cout << endl;
}

// ==================== ВВОД ДАННЫХ ====================

int rdInt(const char* msg)
{
    int v;
    cout << msg;
    while (!(cin >> v))
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод. " << msg;
    }
    cin.ignore(32767, '\n');
    return v;
}

void rdStr(const char* msg, char* buf, int sz)
{
    cout << msg;
    cin.getline(buf, sz);
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".65001");
     SList sl;
    DList dl;
    char buf[256];
    char val[256];

    // Пункт 1: создание обоих списков по вводу пользователя
    cout << "=== Создание списков ===" << endl;
    int n = rdInt("Сколько начальных элементов ввести: ");
    for (int i = 0; i < n; ++i)
    {
        cout << "Элемент " << (i + 1) << ": ";
        cin.getline(buf, sizeof(buf));
        sAddT(sl, buf);
        dAddT(dl, buf);
    }
    sPrint(sl);
    dPrint(dl);

    int ch = -1;
    while (ch != 0)
    {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить k элементов с индекса" << endl;
        cout << "3. Добавить k элементов с индекса" << endl;
        cout << "4. Печать списков" << endl;
        cout << "5. Сортировка вставками" << endl;
        cout << "6. Удвоение списков" << endl;
        cout << "0. Выход" << endl;

        if (!(cin >> ch))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод." << endl;
            continue;
        }
        cin.ignore(32767, '\n');

        if (ch == 1)
        {
            int m = rdInt("1 - в начало, 2 - в конец, 3 - по индексу, 4 - перед элементом, 5 - после элемента: ");
            rdStr("Введите строку: ", buf, sizeof(buf));
            bool ok = false;
            if (m == 1)
            {
                sAddH(sl, buf);
                dAddH(dl, buf);
                ok = true;
            }
            else if (m == 2)
            {
                sAddT(sl, buf);
                dAddT(dl, buf);
                ok = true;
            }
            else if (m == 3)
            {
                int idx = rdInt("Введите индекс: ");
                ok = sAddI(sl, buf, idx);
                ok = ok && dAddI(dl, buf, idx);
            }
            else if (m == 4)
            {
                rdStr("Перед каким элементом: ", val, sizeof(val));
                ok = sAddB(sl, val, buf);
                ok = ok && dAddB(dl, val, buf);
            }
            else if (m == 5)
            {
                rdStr("После какого элемента: ", val, sizeof(val));
                ok = sAddA(sl, val, buf);
                ok = ok && dAddA(dl, val, buf);
            }
            if (ok)
            {
                cout << "Готово." << endl;
            }
            else
            {
                cout << "Операция не выполнена (неверный индекс или элемент не найден)." << endl;
            }
            sPrint(sl);
            dPrint(dl);
        }
        else if (ch == 2)
        {
            int idx = rdInt("Индекс начала удаления: ");
            int k = rdInt("Сколько элементов удалить: ");
            bool ok = sDelK(sl, idx, k);
            ok = ok && dDelK(dl, idx, k);
            if (ok)
            {
                cout << "Удалено " << k << " элементов с позиции " << idx << "." << endl;
            }
            else
            {
                cout << "Не удалось удалить все элементы (неверный индекс или k)." << endl;
            }
            sPrint(sl);
            dPrint(dl);
        }
        else if (ch == 3)
        {
            int idx = rdInt("Индекс вставки: ");
            int k = rdInt("Сколько элементов добавить: ");
            rdStr("База имён (например 'нов'): ", buf, sizeof(buf));
            bool ok = sAddKI(sl, idx, k, buf);
            ok = ok && dAddKI(dl, idx, k, buf);
            if (ok)
            {
                cout << "Добавлено " << k << " элементов (" << buf << "1.." << buf << k << ") с позиции " << idx << "." << endl;
            }
            else
            {
                cout << "Не удалось добавить (неверный индекс)." << endl;
            }
            sPrint(sl);
            dPrint(dl);
        }
        else if (ch == 4)
        {
            sPrint(sl);
            dPrint(dl);
            dPrintRev(dl);
        }
        else if (ch == 5)
        {
            int m = rdInt("1 - по возрастанию, 2 - по убыванию: ");
            int dir = (m == 2) ? -1 : 1;
            sSort(sl, dir);
            dSort(dl, dir);
            if (dir == 1)
            {
                cout << "Сортировка по возрастанию выполнена." << endl;
            }
            else
            {
                cout << "Сортировка по убыванию выполнена." << endl;
            }
            sPrint(sl);
            dPrint(dl);
        }
        else if (ch == 6)
        {
            sDbl(sl);
            dDbl(dl);
            cout << "Списки удвоены." << endl;
            sPrint(sl);
            dPrint(dl);
        }
        else if (ch == 0)
        {
            cout << "Выход из программы." << endl;
        }
        else
        {
            cout << "Нет такого пункта меню." << endl;
        }
    }

    sClr(sl);
    dClr(dl);
    return 0;
}
