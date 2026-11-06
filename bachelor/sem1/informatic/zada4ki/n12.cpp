// ссылки и указатели 3
#include <iostream>
using namespace std;

int main() 
{
    int a = 4, b = 9;
    int* p = &a;     
    int* q = p;       
    int& r = *p;     
    p = &b;          
    
    *q += *p;         
    
    *p = r - 3;      
    
    q = p;            
    
    *q += r;          
    
    cout << a << " " << b << " " << r << endl;
    
    return 0;
}

// p и q указывают на b
// r - ссылка на а