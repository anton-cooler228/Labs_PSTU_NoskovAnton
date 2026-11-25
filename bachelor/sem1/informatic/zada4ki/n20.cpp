// зп
#include <iostream>
#include <string>
#include <clocale>
using namespace std;

struct Employee {
    string name;      // ФИО
    int days;         // отработанные дни
    double rate;      // оплата за день
    double bonus;     // премия
};

int main() {
    setlocale(LC_ALL, ".65001");

    Employee e;

    cout << "Введите ФИО работника: ";
    getline(cin, e.name);

    cout << "Введите количество отработанных дней: ";
    cin >> e.days;

    cout << "Введите оплату за один день (в рублях): ";
    cin >> e.rate;

    cout << "Введите размер премии (в рублях): ";
    cin >> e.bonus;

    if (e.days < 0 || e.rate < 0 || e.bonus < 0) {
        cout << "Ошибка: значения не могут быть отрицательными." << endl;
        return 1;
    }

    double salary = (e.days * e.rate) + e.bonus;

    cout << "\n--- Результат ---" << endl;
    cout << "Работник: " << e.name << endl;
    cout << "Отработано дней: " << e.days << endl;
    cout << "Оплата за день: " << e.rate << " руб." << endl;
    cout << "Премия: " << e.bonus << " руб." << endl;
    cout << "Итоговая заработная плата: " << salary << " руб." << endl;

    return 0;
}
