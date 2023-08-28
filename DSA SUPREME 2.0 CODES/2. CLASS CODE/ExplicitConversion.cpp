//Explicit conversion example
#include<iostream>
using namespace std;

int main(){
    double num1 = 1.2;
    // Explicit conversion from double to int
    int num2 = (int)num1 + 1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    return 0;
}

/*
OUTPUT:
num1 = 1.2
num2 = 2
*/