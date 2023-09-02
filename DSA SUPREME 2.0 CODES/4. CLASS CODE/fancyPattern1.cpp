// Pattern 15: Fancy pattern 1
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Outer loop
    for(int row=0; row<n; row = row+1){
        for(int col=0; col<(2*row+1); col = col+1){
            if(col%2==0){
                cout << row+1 << " ";
            }
            else{
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT: when n is 4
1 
2 * 2 
3 * 3 * 3 
4 * 4 * 4 * 4
*/