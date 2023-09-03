// Pattern 20: Numeric Hollow Inverted Half Pyramid
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Outer Loop
    for(int row=0; row<n; row = row + 1){
        // Inner Loop
        if(row==0){
            for(int col=0; col<n; col = col + 1){
                cout << col + 1 << " ";
            }
        }
        else if(row==n-1){
            cout << n << " ";
        }
        else{
            for(int col=0; col<n-row; col = col + 1){
                if(col==0){
                    cout << row + 1 << " ";
                }
                else if(col==n-row-1){
                    cout << n << " ";
                }
                else{
                    cout << "  ";
                }
            }
        }
        // new line
        cout << endl;
    }
    return 0;
}

/*
OUTPUT: when n is 5
1 2 3 4 5 
2     5 
3   5 
4 5 
5 
*/