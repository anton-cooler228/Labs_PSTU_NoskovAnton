#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const double pi = acos(-1.0);
    const double eps = 1e-4;
    const int k = 10;
    const int n_fixed = 40;

    double a = pi / 5.0;
    double b = pi;
    double h = (b - a) / k;

    cout << fixed << setprecision(4);
    cout << "x\ty(x)\tS_n(x)\tS_eps(x)\n";

    for (int i = 0; i <= k; ++i) {
        double x = a + i * h;
        double y_exact = (pi * pi) / 8.0 - (pi / 4.0) * fabs(x);

        // Случай а) для заданного n
        double s_n = 0.0;
        for (int m = 1; m <= n_fixed; ++m) {
            int coeff = 2 * m - 1;
            s_n += cos(coeff * x) / (coeff * coeff);
        }

        // Случай б) для заданной точности
        double s_eps = 0.0;
        int m = 1;
        
        // Сначала вычисляем первый член, чтобы условие цикла имело смысл
        int coeff = 2 * m - 1;
        double term = cos(coeff * x) / (coeff * coeff);

        while (fabs(term) >= eps) {
            s_eps += term;
            ++m;
            coeff = 2 * m - 1;
            term = cos(coeff * x) / (coeff * coeff);
        }

        cout << x << "\t" << y_exact << "\t" << s_n << "\t" << s_eps << "\n";
    }

    return 0;
}