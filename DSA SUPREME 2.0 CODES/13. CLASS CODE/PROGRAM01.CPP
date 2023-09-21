// Program 01: Divide two number using Binary search without using any / and % operator
#include<iostream>
using namespace std;

// Divide two number using Binary search
int getQuotient(int dividend,int divisor){
    int s = 0;
    int e= dividend;
    int mid = s+(e-s)/2;
    int ANS = -1;

    while (s<=e)
    {
        // Return quotient
        if(mid * divisor == dividend){
            return mid;
        }
        // Goto to left side to get possible quotient
        else if(mid * divisor > dividend){
            e = mid - 1;
        }
        // Store possible mid in ANS and goto to right side to get possible quotient
        else if(mid * divisor < dividend){
            ANS = mid;
            s = mid + 1;
        }
        
        // Updated mid
        mid = s+(e-s)/2;
    }
    return ANS;
}

// Time Complexity: O(logN), where N is dividend.
// Space Complexity: O(1)

int main(){
    int dividend = 29, divisor = -7;

    int quotient = getQuotient(abs(dividend),abs(divisor));

    // Now we need to decide ki sign konsa lagaye +VE ya -VE
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
        quotient *=-1;
    }
    cout<<"Quotient: "<<quotient<<endl;
}

/*
Examples 01:
Input: dividend = 10, divisor = 2
Output: 5
Explanation: 10/2 = 5

Examples 02:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333… which is truncated to 3

Examples 03:
Input: dividend = 10, divisor = -2
Output: -5
Explanation: 10/-2 = -5.

Examples 04:
Input: dividend = -10, divisor = 2
Output: -5
Explanation: -10/2 = -5.
*/