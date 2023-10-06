// PROGRAM 02: Find GCD/HCF using Euclids Algorithm (GFG)

class Solution
{
	public:
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
};

/*
Time Complexity: O(A) when A<B or O(B) when A>B
Space Complexity: O(1), no extra space used
*/

/*
Example 1:
Input: A = 3, B = 6
Output: 3
Explanation: GCD of 3 and 6 is 3

Example 2:
Input: A = 1, B = 1
Output: 1
Explanation: GCD of 1 and 1 is 1
*/