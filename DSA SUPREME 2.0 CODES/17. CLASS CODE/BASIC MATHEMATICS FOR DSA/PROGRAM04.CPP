// PROGRAM 04: Fast exponentiation (GFG)
#include<iostream>
using namespace std;

// ✅APPROACH 01: Naive solution
int slowExponentiation(int A, int B){
    int ans = 1;
    for(int i=0; i<B; i++){
        ans *= A;
    }

    return ans;
}

// ✅APPROACH 02: Better solution
int fastExponentiation(int A, int B){
    int ans = 1;

    while(B > 0){

        if(B & 1){ // When B is odd number
            ans = ans * A;
        }

        A = A * A;
        B = B>>1; // B is divided by 2 until B>0
    }

    return ans;
}

int main(){
    int A, B;
    cin>>A>>B;

    int ans = fastExponentiation(A,B);

    cout<<ans<<endl;

    return 0;
}

/*
✅APPROACH 01: Naive solution
Time Complexity: O(B), where B is a exponentiation power
Space Complexity: O(1)
*/

/*
✅APPROACH 02: Better solution
Time Complexity: O(Log B), where B is a exponentiation power
Space Complexity: O(1)
*/
