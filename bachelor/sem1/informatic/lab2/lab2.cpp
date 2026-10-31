#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const double eps = 1e-4;
    double sum = 0.0;
    double lgFact = 0.0; // lg(1!) = 0
    int n = 2;

    cout << "Сумма ряда: a_n = lg(n!) * e^(-n*sqrt(n)), точность eps = " << eps << "\n";
    cout << fixed << setprecision(6);

    // Вычисляем первый член (для n = 2) до входа в цикл
    lgFact += log10(static_cast<double>(n));
    double term = lgFact * exp(-n * sqrt(static_cast<double>(n)));

    // Цикл работает, пока не превышен лимит итераций И текущий член ещё значим
    while (n <= 1000 && fabs(term) >= eps) 
    {
        sum += term;
        cout << "n = " << n << ": a_n = " << term
             << ", текущая сумма = " << sum << "\n";

        ++n;
        lgFact += log10(static_cast<double>(n));
        term = lgFact * exp(-n * sqrt(static_cast<double>(n)));
    }

    // Если цикл остановился из-за малого term (а не из-за n > 1000), выводим сообщение
    if (n <= 1000) 
    {
        cout << "n = " << n << ": |a_n| = " << fabs(term)
             << " < eps, суммирование остановлено.\n";
    } 
    else 
    {
        cout << "Достигнут лимит итераций (n > 1000).\n";
    }

    cout << "\nРезультат: сумма ряда = " << sum << "\n";
    return 0;
}
