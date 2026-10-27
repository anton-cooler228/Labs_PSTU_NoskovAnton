#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const double eps = 1e-4;
    double sum = 0.0;
    double lgFact = 0.0; // lg(1!) = 0

    cout << "Сумма ряда: a_n = lg(n!) * e^(-n*sqrt(n)), точность eps = " << eps << "\n";
    cout << fixed << setprecision(6);

    for (int n = 2; n <= 1000; ++n) {
        lgFact += log10(static_cast<double>(n)); // lg(n!) = lg((n-1)!) + lg(n)

        double term = lgFact * exp(-n * sqrt(static_cast<double>(n)));

        if (fabs(term) < eps) {
            cout << "n = " << n << ": |a_n| = " << fabs(term)
                 << " < eps, суммирование остановлено.\n";
            break;
        }

        sum += term;
        cout << "n = " << n << ": a_n = " << term
             << ", текущая сумма = " << sum << "\n";
    }

    cout << "\nРезультат: сумма ряда = " << sum << "\n";
    return 0;
}
