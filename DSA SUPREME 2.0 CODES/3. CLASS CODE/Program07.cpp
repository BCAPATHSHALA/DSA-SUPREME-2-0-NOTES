// Check if number is prime or not
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    if(n<2){
        cout << n << " is not prime number" << endl;
    }
    else{
        for(int i = 2; i < n; i = i + 1){
            if(n % i == 0){
                cout << n << " is not prime number" << endl;
            }
        }
        cout << n << " is prime number" << endl;
    }
    return 0;
}

/*
OUTPUT:
Enter a number
-1
-1 is not prime number

Enter a number
0
0 is not prime number

Enter a number
1
1 is not prime number

Enter a number
2
2 is prime number
*/