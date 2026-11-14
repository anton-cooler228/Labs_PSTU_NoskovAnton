#include <clocale>
#include <iostream>
using namespace std;

const int MAXLEN = 256;
const int MAXW = 128;

// Ввод строки с клавиатуры
void Gets(char s[])
{
    cin.getline(s, MAXLEN);
}

// Сравнение двух слов
bool sameWord(char a[], char b[])
{
    int i = 0;
    bool same = true;
    while (a[i] != '\0' && b[i] != '\0' && same)
    {
        if (a[i] != b[i])
        {
            same = false;
        }
        else
        {
            i++;
        }
    }
    return same && a[i] == b[i];
}

// Поиск слова в таблице; возвращает индекс или -1
int findWord(char words[][MAXLEN], int num, char w[])
{
    int idx = -1;
    for (int i = 0; i < num && idx < 0; i++)
    {
        if (sameWord(words[i], w))
        {
            idx = i;
        }
    }
    return idx;
}

int main()
{
    setlocale(LC_ALL, ".65001");

    char s[MAXLEN];
    char words[MAXW][MAXLEN];
    char w[MAXLEN];
    int cnt[MAXW];
    int num = 0;
    int i = 0;
    int len = 0;
    int best = 0;
    bool done = false;

    cout << "Ввод строки: ";
    Gets(s);

    while (!done)
    {
        while (s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '.' || s[i] == '\0')
        {
            done = true;
        }
        else
        {
            len = 0;
            while (s[i] != ' ' && s[i] != '.' && s[i] != '\0')
            {
                w[len] = s[i];
                len++;
                i++;
            }
            w[len] = '\0';

            int idx = findWord(words, num, w);
            if (idx < 0)
            {
                for (int k = 0; k <= len; k++)
                {
                    words[num][k] = w[k];
                }
                cnt[num] = 1;
                num++;
            }
            else
            {
                cnt[idx]++;
            }
        }
    }

    if (num == 0)
    {
        cout << "Слов в строке нет\n";
    }
    else
    {
        for (int j = 1; j < num; j++)
        {
            if (cnt[j] > cnt[best])
            {
                best = j;
            }
        }
        cout << "Чаще всего встречается слово: " << words[best];
        cout << " (" << cnt[best] << " раз)\n";
    }

    return 0;
}
