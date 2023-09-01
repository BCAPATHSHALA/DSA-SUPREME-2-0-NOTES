// Pattern 2: Rectangle pattern
#include<iostream>
using namespace std;

int main(){
    int n = 3;

    // outer loop traverse from 0 to n-1
    for(int row = 0; row < n; row = row + 1){
        // inner loop traverse from 0 to n+1
        for(int col = 0; col < (n+2); col = col + 1){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT:
* * * * *
* * * * *
* * * * *
*/