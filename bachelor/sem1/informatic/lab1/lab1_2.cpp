#include <iostream>
#include <clocale> // директивы

using namespace std; // упростим код

int main() 
{
    setlocale(LC_ALL, ".65001");   // подключаем кириллицу

    int n, m;

    // запрос ввода у пользователя
    cin >> n >> m;

    // Копируем значения, чтобы каждое выражение работало с исходными n и m
    int n1 = n, m1 = m;
    int n2 = n, m2 = m;
    int n3 = n, m3 = m;

    // 1) ++n * ++m
    int res1 = ++n1 * ++m1;
    cout << "\n1) ++n * ++m = " << res1
              << " (после: n=" << n1 << ", m=" << m1 << ")\n";

    // 2) m++ < n
    bool res2 = (m2++ < n2);
    cout << "2) m++ < n = " << boolalpha << res2
              << " (после: m=" << m2 << ", n=" << n2 << ")\n";

    // 3) n++ > m
    bool res3 = (n3++ > m3);
    cout << "3) n++ > m = " << boolalpha << res3
              << " (после: n=" << n3 << ", m=" << m3 << ")\n";
              
    return 0;
}
