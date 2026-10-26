#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "65001");
    const double eps = 1e-4;
    double sum = 0.0;
    double log_fact = 0.0;
    int n = 1;

    while (true) {
        log_fact += log10(n);
        double term = log_fact * exp(-n * sqrt(n));
        if (fabs(term) < eps) break;
        sum += term;
        ++n;
    }

    cout << "Сумма ряда с точностью 10^-4: " << fixed << setprecision(4) << sum << endl;
    return 0;
}
