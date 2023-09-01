// Pattern 1: Square pattern
#include<iostream>
using namespace std;

int main(){
    int n = 4;

    // outer loop traverse from 0 to n-1
    for(int row = 0; row < n; row = row + 1){
        // inner loop traverse from 0 to n-1
        for(int col = 0; col < n; col = col + 1){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT:
* * * *
* * * *
* * * *
* * * *
*/