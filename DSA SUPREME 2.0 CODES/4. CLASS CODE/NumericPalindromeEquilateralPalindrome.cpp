// Pattern 21: Numeric Palindrome Equilateral Pyramid
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    // Outer loop
    for(int row=0; row<n; row++){
        // Todo 01: First
        for(int col=0;col<(n-row-1);col++){
            cout<<"  ";
        }
        // Todo 02: Second
        int number = 0;
        for(int col=0;col<(row+1);col++){
            number = col+1;
            cout<<number<<" ";
        }
        // Todo 03: Third
        for(number;number>0;){
            number = number-1;
            if(number>0)
            cout<<number<<" ";
        }
        // New line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n is 5
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 
*/