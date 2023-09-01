// Pattern 3: Hollow Rectangle pattern
#include<iostream>
using namespace std;

int main(){
    int n = 5;

    // outer loop traverse from 0 to n-1
    for(int row = 0; row < n; row = row + 1){
        // inner loop traverse from 0 to n-1
        for(int col = 0; col < n; col = col + 1){
            // if zeroth or last row, then print n times star
            if(row == 0 || row == n-1){
                cout << "* ";
            }
            else{
                // if zeroth or last col, then print 1 time star
                if(col == 0 || col == n-1){
                    cout << "* ";
                }
                else{
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT:
* * * * * 
*       * 
*       * 
*       * 
* * * * * 
*/