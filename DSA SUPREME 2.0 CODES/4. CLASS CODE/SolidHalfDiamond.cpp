// Pattern 23: Solid Half Diamond
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    // Todo 01: First
    for(int row=0;row<(n-(n/2));row++){
        for(int col=0;col<(row+1);col++){
            cout<<"* ";
        }
        // New line
        cout<<endl;
    }
    // Todo 02: Second
    for(int row=0;row<(n/2);row++){
        for(int col=0;col<((n/2)-row);col++){
            cout<<"* ";
        }
        // New line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT:when n is 7
* 
* * 
* * * 
* * * * 
* * * 
* * 
* 
*/