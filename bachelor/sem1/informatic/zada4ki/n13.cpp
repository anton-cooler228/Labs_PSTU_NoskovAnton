// ссылки и указатели 4
#include <iostream>
using namespace std;

int main() 
{
    int a = 5, b = 8;
    int& r = a;     
    int& s = a;     
    int copy = a;   

    r = b;           
    s += 2;          
    b = copy;        

    cout << a << " " << b << " " << r << " " << s << " " << copy << endl;

    return 0;
}

// copy при изменении r и s не меняется