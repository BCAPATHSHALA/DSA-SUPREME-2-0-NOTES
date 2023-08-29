// Find the factorial of a number
#include<iostream>
using namespace std;

int main(){
    int n, fac = 1;
    cout << "Enter a number " << endl;
    cin >> n;
    if(n < 0){
        cout << "Invalid input" << endl;
    }
    else if(n == 0){
        cout << "Factorial of " << n << "! is " << fac << endl;
    }
    else if(n > 0){
        for( n ; n > 0; n = n - 1 ){
            fac = fac * n;
        }
        cout << "Factorial of " << n << "! is " << fac << endl;
    }
    return 0;
}

/*
OUTPUT:
Enter a number 
-1
Invalid input

Enter a number 
0
Factorial of 0! is 1

Enter a number 
5
Factorial of 5! is 120
*/