// ссылки и указатели 5
#include <iostream>
using namespace std;

int main() 
{
    int a = 2, b = 5, c = 8;
    int* p = &a;      
    int& r = a;       
    int copy = *p;   

    *p = b;           
    p = &c;           
    r = *p;          
    *p = b + copy;    
    p = &b;           
    *p = r - copy;    
    r++;              

    cout << a << " " << b << " " << c << " " << copy << endl;

    return 0;
}

// В конце программы указатель p указывает на переменную b
// r — это ссылка на переменную a