// Pattern 10 --> Dimond Pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int n = num/2;

    //TODO 01: Full Pyramid
    for(int row=0; row<n; row++){
        // print space
        for(int col=0; col<n-row-1; col++){
            cout << " ";
        }
        // print star
        for(int col=0; col<row+1; col++){
            cout << "* ";
        }
        // new line
        cout<<endl;
    }
    //TODO 02: Inverted Full Pyramid
     for(int row=0; row<n; row++){
        // print space
        for(int col=0; col<row; col++){
            cout << " ";
        }
        // print star
        for(int col=0; col<n-row; col++){
            cout << "* ";
        }
        // new line
        cout<<endl;
    }

    return 0;
}

/*
OUTPUT: when n = 8
   * 
  * * 
 * * * 
* * * * 
* * * * 
 * * * 
  * * 
   * 
*/