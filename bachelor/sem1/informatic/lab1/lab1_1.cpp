#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale> // подключаем директивы

using namespace std;

int main() 
{ 
    setlocale(LC_ALL, ".65001");   // подключаем кириллицу

    float a_f = 1000.0f, b_f = 0.0001f;
    
    // Промежуточные значения для float
    float r1_f = a_f - b_f;                      // a - b
    cout << fixed << setprecision(15);
    cout << "float: a - b = " << r1_f << "\n";

    float pow_r1_f = pow(r1_f, 3);               // (a-b)^3     
    cout << "float: (a - b)^3 = " << pow_r1_f << "\n";

    float a3_f = a_f * a_f * a_f;                // a^3
    float ta2b_f = 3.0f * a_f * a_f * b_f;       // 3b*a^2
    cout << "float: a^3 = " << a3_f << "\n";
    cout << "float: 3 * a^2 * b = " << ta2b_f << "\n";

    float r2_f = a3_f - ta2b_f;                  // a^3 - 3*a^2*b  
    cout << "float: (a^3 - 3*a^2*b) = " << r2_f << "\n";

    float ch_f = pow_r1_f - r2_f;                // (a - b)^3 - (a^3 - 3*a^2*b)
    cout << "float: числитель = (a - b)^3 - (a^3 - 3*a^2*b) = " << ch_f << "\n";

    float b3_f = b_f * b_f * b_f;               // b^3
    cout << "float: b^3 = " << b3_f << "\n";

    float tab2_f = 3.0f * a_f * b_f * b_f;     // 3ab^2
    cout << "float: 3ab^2 = " << tab2_f << "\n";

    float zn_f = b3_f - tab2_f;                // знаменатель b^3 - 3*a*b^2
    cout << "float: знаменатель = b^3 - 3*a*b^2 = " << zn_f << "\n\n";

    double a_d = 1000.0, b_d = 0.0001; // --- Продолжение для double ---

    double r1_d = a_d - b_d;                     // a - b
    cout << "double: a - b = " << r1_d << "\n";

    double pow_r1_d = pow(r1_d, 3);             // (a-b)^3
    cout << "double: (a - b)^3 = " << pow_r1_d << "\n";

    double a3_d = a_d * a_d * a_d;               // a^3
    double ta2b_d = 3.0 * a_d * a_d * b_d;       // 3b*a^2
    cout << "double: a^3 = " << a3_d << "\n";
    cout << "double: 3 * a^2 * b = " << ta2b_d << "\n";

    double r2_d = a3_d - ta2b_d;                 // a^3 - 3*a^2*b
    cout << "double: (a^3 - 3*a^2*b) = " << r2_d << "\n";

    double ch_d = pow_r1_d - r2_d;               // числитель
    cout << "double: числитель = (a - b)^3 - (a^3 - 3*a^2*b) = " << ch_d << "\n";

    double b3_d = b_d * b_d * b_d;               // b^3
    cout << "double: b^3 = " << b3_d << "\n";

    double tab2_d = 3.0 * a_d * b_d * b_d;       // 3ab^2
    cout << "double: 3ab^2 = " << tab2_d << "\n";

    double zn_d = b3_d - tab2_d;                 // знаменатель
    cout << "double: знаменатель = b^3 - 3*a*b^2 = " << zn_d << "\n\n";

    // Итоговые результаты
    cout << "Результат (float): " << ch_f / zn_f << "\n";
    cout << "Результат (double): " << ch_d / zn_d << "\n";
    
    return 0;
}

