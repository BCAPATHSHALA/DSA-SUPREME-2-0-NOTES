// Multiply two numbers by taking input from user
#include<iostream>
using namespace std;

int main(){
    int a, b;

    cout << "Enter a" << endl;
    cin >> a;

    cout << "Enter b" << endl;
    cin >> b;

    int result = a * b;
    cout << "Multiply of a and b is " << result << endl;

    return 0;
}

/*
OUTPUT:
Enter a
2
Enter b
3
Multiply of a and b is 6
*/