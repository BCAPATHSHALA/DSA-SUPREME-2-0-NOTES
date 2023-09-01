// Pattern 09: Inverted Full Pyramid 
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    // outer loop
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
OUTPUT: when n = 5
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
*/