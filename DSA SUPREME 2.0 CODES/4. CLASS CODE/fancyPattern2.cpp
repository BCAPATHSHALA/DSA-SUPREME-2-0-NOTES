// Pattern 16: Fancy pattern 2
#include<iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int n=num/2;

    // Todo 1: First
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
    // Todo 2: Second
    for(int row=0; row<n; row = row+1){
        for(int col=0; col<(2*n-2*row-1); col = col+1){
            if(col%2==0){
                cout << n-row << " ";
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
4 * 4 * 4 * 4 
3 * 3 * 3 
2 * 2 
1 
*/