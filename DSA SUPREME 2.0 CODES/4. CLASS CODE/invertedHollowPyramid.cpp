// Pattern 12 --> Inverted Hollow Full Pyramid
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    // outer loop
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
OUTPUT: when n = 5
*       *
 *     *
  *   *
   * *
    * 
*/