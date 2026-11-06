// ссылки и указатели 2
#include <iostream>
using namespace std;

int main() 
{
    int a = 12;
    int* ptr = &a;      
    int copy = *ptr;    

    (*ptr)++;           

    cout << a << " " << copy << endl;

    return 0;
}

// copy - переменная в своей ячейке памяти, нет связи с а
// *ptr - указатель-псевдоним а, не занимает отдельную память, любое изменение меняет a.