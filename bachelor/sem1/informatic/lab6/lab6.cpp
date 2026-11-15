#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

const int MAXLEN = 256;
const int MAXW = 128;

void Gets(char s[]) {
    cin.getline(s, MAXLEN);
}

bool sameWord(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

int findWord(char words[][MAXLEN], int num, char w[]) {
    for (int i = 0; i < num; i++) {
        if (sameWord(words[i], w)) {
            return i;
        }
    }
    return -1;
}

// Функция для очистки буфера слова
void clearWord(char w[]) {
    for (int i = 0; i < MAXLEN; i++) {
        w[i] = '\0';
    }
}

int main() {
    // Настройка консоли для кириллицы (Windows)
    SetConsoleCP(1251);          // кодировка ввода — Windows-1251
    SetConsoleOutputCP(1251);   // кодировка вывода — Windows-1251

    // Установка локали
    setlocale(LC_ALL, "Russian");
    setlocale(LC_CTYPE, "ru_RU.CP1251");

    char s[MAXLEN];
    char w[MAXLEN] = {0};
    char words[MAXW][MAXLEN] = {0};
    int cnt[MAXW] = {0};
    int num = 0;
    int best = 0;

    cout << "Ввод строки: ";
    Gets(s);

    int len = 0;
    int i = 0;

    while (s[i] != '\0') {
        char c = s[i];

        // Проверяем разделители (пробелы и знаки препинания)
        if (c == ' ' || c == '\t' || c == '.' || c == ',' ||
            c == '!' || c == '?' || c == ';' || c == ':') {
            if (len > 0) {
                w[len] = '\0';
                int idx = findWord(words, num, w);

                if (idx < 0) {
                    strcpy(words[num], w);
                    cnt[num] = 1;
            num++;
                } else {
                    cnt[idx]++;
                }
                len = 0;
                clearWord(w);  // очищаем буфер
            }
        } else if (len < MAXLEN - 1) {
            w[len++] = c;
        }
        i++;
    }

    // Обрабатываем последнее слово
    if (len > 0) {
        w[len] = '\0';
        int idx = findWord(words, num, w);
        if (idx < 0) {
            strcpy(words[num], w);
            cnt[num] = 1;
            num++;
        } else {
            cnt[idx]++;
        }
    }

    // Находим самое частое слово
    if (num > 0) {
        best = 0;
        for (int j = 1; j < num; j++) {
            if (cnt[j] > cnt[best]) {
                best = j;
            }
        }

        cout << "Чаще всего встречается слово: " << words[best];
        cout << " (" << cnt[best] << " раз)\n";
    } else {
        cout << "Не удалось найти наиболее частое слово.\n";
    }

    return 0;
}
