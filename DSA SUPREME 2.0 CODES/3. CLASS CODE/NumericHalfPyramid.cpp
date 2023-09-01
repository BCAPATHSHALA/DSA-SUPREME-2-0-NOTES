// Pattern 6: Numeric Half Pyramid pattern
#include<iostream>
using namespace std;

int main(){
    int n = 5;

    // outer loop traverse from 0 to n-1
    for(int row = 0; row < n; row = row + 1){
        // inner loop traverse from 0 to (row+1)-1 and print col+1
        for(int col = 0; col < (row + 1); col = col + 1){
            cout << col+1 << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT:
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
*/