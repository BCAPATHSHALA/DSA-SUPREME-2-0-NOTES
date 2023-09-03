// Pattern 24: Floyd Triangle
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int number=0;

    // Outer loop
    for(int row=0;row<n;row++){
        // Inner loop
        for(int col=0;col<(row+1);col++){
            number = number + 1;
            cout<<(number)<<" ";
        }
        // New line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n is 6
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 21 
*/