#include<iostream>
using namespace std;

int main(){
    int a = 10;
    cout<< "value of a: " << a << endl;
    cout<< "address of a: " << &a << endl;

    // Pointer creation
    int* p = &a;

    // Accessing value stored at address stored in ptr
    cout<< "value of a: " << *p << endl;
    cout<< "address of a: " << p << endl;  
    cout<< "address of p: " << &p << endl;
    cout<< "size of p: " << sizeof(p) << endl;
    cout<< "size of a: " << sizeof(a) << endl;

    return 0;
}

/*
OUTPUT:
value of a: 10
address of a: 0x7ffd33b6826c
value of a: 10
address of a: 0x7ffd33b6826c
address of p: 0x7ffd33b68260
size of p: 8
size of a: 4
*/