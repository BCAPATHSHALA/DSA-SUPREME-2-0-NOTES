// Pattern 14 --> Flipped Solid Diamond pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int n = num/2;

    //? FIRST PART
    for(int row=0; row<n; row++){
        // TODO 01: inverted pyramid 1
        for(int col=0; col<n-row; col++){
            cout << "* ";
        }
         // TODO 02: full pyramid
        for(int col=0; col<2*row+1; col++){
           cout << "- ";
        }
        // TODO 03: inverted pyramid 2
        for(int col=0; col<n-row; col++){
            cout << "* ";
        }
        // new line
        cout<<endl;
    }
    //? SECOND PART
    for(int row=0; row<n; row++){
        // TODO 01: inverted pyramid 1
        for(int col=0; col<row+1; col++){
            cout << "* ";
        }
         // TODO 02: full pyramid
        for(int col=0; col<2*n-2*row-1; col++){
           cout << "- ";
        }
        // TODO 03: inverted pyramid 2
        for(int col=0; col<row+1; col++){
            cout << "* ";
        }
        // new line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n = 8
* * * * - * * * * 
* * * - - - * * * 
* * - - - - - * * 
* - - - - - - - * 
* - - - - - - - * 
* * - - - - - * * 
* * * - - - * * * 
* * * * - * * * * 

*/