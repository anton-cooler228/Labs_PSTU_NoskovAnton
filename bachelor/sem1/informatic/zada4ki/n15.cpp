// длиннее ли слово 5 символов
#include <iostream>
#include <string>
#include <algorithm>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    string word;

    cout << "Ввод слова: ";
    cin >> word;

    if (word.length() > 5)
    {
        word = 'X';
    }
    else
    {
        word[word.length() - 1] = 'X';
    }

    reverse(word.begin(), word.end());

    cout << word << endl;

    return 0;
}
