// Pattern 13 --> Hollow Diamond pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    int n = num/2;

    // * Hollow Full Pyramid
    for(int row=0; row<n; row++){
        // TODO 01: First
        for(int col=0; col<n-row-1; col++){
            cout << " ";
        }
         // TODO 02: Second
        for(int col=0; col<row+1; col++){
           if(col==0 || col==row+1-1){
             cout << "* ";
           }
           else{
            cout << "  ";
           }
        }
        // new line
        cout<<endl;
    }
    // * Inverted Hollow Full Pyramid
    for(int row=0; row<n; row++){
        // TODO 01: First
        for(int col=0; col<row; col++){
            cout << " ";
        }
        // TODO 02: Second
        for(int col=0; col<n-row; col++){
           if(col==0 || col==(n-row)-1){
             cout << "* ";
           }
           else{
            cout << "  ";
           }
        }
        // new line
        cout<<endl;
    }
    return 0;
}

/*
OUTPUT: when n = 10
    * 
   * * 
  *   * 
 *     * 
*       * 
*       * 
 *     * 
  *   * 
   * * 
    * 
*/