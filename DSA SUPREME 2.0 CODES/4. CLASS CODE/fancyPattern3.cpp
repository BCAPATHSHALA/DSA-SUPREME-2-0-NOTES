// Pattern 18: Fancy pattern 3 (Numerical Hollow Half Pyramid)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Outer loop
    for(int row=0; row<n; row = row+1){
        // Inner loop
        if(row==0){
            cout << row+1 << " ";
        }
        else if(row==n-1){
            for(int col=0; col<n; col = col + 1){
                cout << col + 1 << " ";
            }
        }
        else{
            for(int col=0; col<row+2; col = col + 1){
                if(col==0){
                    cout << col + 1 << " ";
                }
                else if(col==row+2-1){
                    cout << col << " ";
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
1 
1  2 
1   3 
1    4 
1 2 3 4 5 

*/