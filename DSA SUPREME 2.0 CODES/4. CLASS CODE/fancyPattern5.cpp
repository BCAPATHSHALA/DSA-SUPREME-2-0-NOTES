// Pattern 22: Fancy pattern 5
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // Outer loop
    for(int row=0;row<n;row++){
        // Todo 01: First
        for(int col=0;col<(n-row+3);col++){
            cout<< "* ";
        }
        // Todo 02: Second
        for(int col=0;col<(2*row+1);col++){
            // If col is even
            if(col%2==0){
                cout<<(row+1)<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        // Todo 03: Third
        for(int col=0;col<(n-row+3);col++){
            cout<< "* ";
        }
        // New line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n is 5
* * * * * * * * 1 * * * * * * * * 
* * * * * * * 2 * 2 * * * * * * * 
* * * * * * 3 * 3 * 3 * * * * * * 
* * * * * 4 * 4 * 4 * 4 * * * * * 
* * * * 5 * 5 * 5 * 5 * 5 * * * * 
*/