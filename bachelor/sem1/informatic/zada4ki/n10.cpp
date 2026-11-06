// ссылки и указатели 1
#include <iostream>
using namespace std;

int main() 
{
    int a = 10;
    int b = 20;
    int& r = a;

    r = b;     
    r++;     

    cout << a << " " << b << endl;

    return 0;
}

// Через ссылку r изменяется объект a