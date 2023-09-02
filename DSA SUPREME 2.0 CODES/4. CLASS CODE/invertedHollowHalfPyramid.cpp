// Pattern 17: Inverted Hollow Half Pyramid 
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Outer loop
    for(int row=0; row<n; row = row+1){
        for(int col=0; col<n-row; col = col+1){
            if(row==0 || row==n-1){
                cout << "* ";
            }
            else{
                if(col==0 || col==(n-row-1)){
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
OUTPUT: when n is 6
* * * * * * 
*       * 
*     * 
*   * 
* * 
* 
*/