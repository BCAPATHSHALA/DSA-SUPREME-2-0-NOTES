// Print max of three numbers
#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cout << "Enter number a = ";
    cin >> a;
    cout << "Enter number b = ";
    cin >> b;
    cout << "Enter number c = ";
    cin >> c;

    if(a>b && a>c){
        cout << "Maximum number is a" << endl;
    }
    else if(b>a && b>c){
        cout << "Maximum number is b" << endl;
    }
    else{
        cout << "Maximum number is c" << endl;
    }
}

/*
OUTPUT:
Enter number a = 1
Enter number b = 2
Enter number c = 3
Maximum number is c
*/