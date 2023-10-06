// PROGRAM 03: Find LCM (GFG)
#include <iostream>
using namespace std;

// GCD of two positive integer numbers
int gcd(int A, int B) 
{ 
	if(A==0) return B;
	if(B==0) return A;
	    
	while(A != B){
	   if(A>B){
	       A = A - B;
	   }
	   else{
	       B = B - A;
	   }
	}
} 

int main() {
    int A = 4, B = 8;
    int lcm = (A*B)/gcd(A,B);
    cout<<lcm<<endl;
    return 0;
}

/*
Time Complexity: O(A) when A<B or O(B) when A>B
Space Complexity: O(1), no extra space used
*/

/*
Example 1:
Input: A = 3, B = 6
Output: 6

Example 2:
Input: A = 1, B = 1
Output: 1
*/