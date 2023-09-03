// Pattern 25: Butterfly Pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int n=(num/2);

    // TODO PART 01
    for(int row=0;row<n;row++){
        // Todo 01: First
        for(int col=0;col<(row+1);col++){
            cout<<"* ";
        }
        // Todo 02: Second
        for(int col=0;col<(num-(2*row)-2);col++){
            cout<<"  ";
        }
        // Todo 03: Third
        for(int col=0;col<(row+1);col++){
            cout<<"* ";
        }
        // New line
        cout<<endl;
    }
    // TODO PART 02
    for(int row=0;row<n;row++){
        // Todo 04: Fourth
        for(int col=0;col<(n-row);col++){
            cout<<"* ";
        }
        // Todo 05: Fifth
        for(int col=0;col<(2*row);col++){
            cout<<"  ";
        }
        // Todo 06: Sixth
        for(int col=0;col<(n-row);col++){
            cout<<"* ";
        }
        // New line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n is 8
*             * 
* *         * * 
* * *     * * * 
* * * * * * * * 
* * * * * * * * 
* * *     * * * 
* *         * * 
*             * 
*/