#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;          // количество колец
const int W = N * 2 + 1;  // ширина самого широкого кольца (нечётная)

int t[3][N];              // стержни: t[0], t[1], t[2] — массивы колец; 0 = пусто
int h[3];                 // высоты (сколько колец на каждом стержне)
int step = 0;             // счётчик шагов

// Рисуем состояние всех стержней
void draw() 
{
    cout << "\nШаг " << step << ":\n";

    // Находим максимальную высоту для красивого вывода
    int maxH = N;

    for (int row = maxH - 1; row >= 0; --row) 
    {
        for (int pole = 0; pole < 3; ++pole) 
        {
            cout << "  "; // отступ слева от стержня

            if (h[pole] <= row) 
            {
                // Пусто: рисуем только стержень
                cout << setw(W / 2) << "" << "|" << setw(W / 2) << "";
            } 
            else 
            {
                int ring = t[pole][row]; // размер кольца (1..N)
                int w = ring * 2 - 1;    // ширина кольца
                int space = (W - w) / 2;

                for (int k = 0; k < space; ++k) cout << " ";
                for (int k = 0; k < w; ++k)   cout << "#";
                for (int k = 0; k < space; ++k) cout << " ";
            }
            cout << "   "; // расстояние между стержнями
        }
        cout << "\n";
    }

    // Подписи стержней
    cout << "   A   B   C   \n\n";
}

// Переместить одно кольцо с from на to
void moveOne(int from, int to) 
{
    int ring = t[from][h[from] - 1];
    h[from]--;

    t[to][h[to]] = ring;
    h[to]++;

    step++;
    draw();
}

// Ханойская башня: n колец с from на to через via
void hanoi(int n, int from, int to, int via) 
{
    if (n == 0) return;

    hanoi(n - 1, from, via, to);
    moveOne(from, to);
    hanoi(n - 1, via, to, from);
}

int main() 
{
    // Инициализация: все кольца на стержне 0 (A), от большего к меньшему
    for (int i = 0; i < N; ++i) 
    {
        t[0][i] = N - i; // сверху вниз: N, N-1, ..., 1
    }
    h[0] = N;
    h[1] = 0;
    h[2] = 0;

    cout << "Ханойская башня, N = " << N << "\n";
    draw(); // начальное состояние

    hanoi(N, 0, 2, 1); // перенести с A (0) на C (2) через B (1)

    cout << "Готово! Всего ходов: " << step << "\n";
    return 0;
}
