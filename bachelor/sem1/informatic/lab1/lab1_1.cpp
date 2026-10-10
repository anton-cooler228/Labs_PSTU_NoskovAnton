#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale> // представлены директивы

using namespace std; // выводить станет удобнее

int main() { 
    setlocale(LC_ALL, ".65001");   // подключаем кириллицу

    float a_f = 1000.0f, b_f = 0.0001f;
    float num_f = pow(a_f - b_f, 3) - (a_f * a_f * a_f - 3.0f * a_f * a_f * b_f);
    float den_f = b_f * b_f * b_f - 3.0f * a_f * b_f * b_f; // решаем для float

    double a_d = 1000.0, b_d = 0.0001;
    double num_d = pow(a_d - b_d, 3) - (a_d * a_d * a_d - 3.0 * a_d * a_d * b_d);
    double den_d = b_d * b_d * b_d - 3.0 * a_d * b_d * b_d; // решаем для double

    cout << fixed << setprecision(15);
    cout << "Результат (float): " << num_f / den_f << "\n";
    cout << "Результат (double): " << num_d / den_d << "\n"; // вывод
    cout << "Видим, насколько отличается использование разных типов данных на С++" << "\n";
    cout << "Это не ошибка, а прямое следствие разной точности хранения вещественных чисел в этих типах." << "\n";
    cout << "float (одинарная точность, 32 бита), double (двойная точность, 64 бита), количество значимых цифр для хранения различно." << "\n";
    
    return 0; // никуда без return
}
