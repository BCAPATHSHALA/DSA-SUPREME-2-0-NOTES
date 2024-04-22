// 13. Pow(x, n) (Leetcode-50)

/*
Approaches:
1. Naive Approach
2. Binary Exponentiation
3. Fast Exponentiation
*/


// Approach 2: Binary Exponentiation
/*
Time Complexity: O(logn)
Space Complexity: O(1)
Where, n is power
*/
class Solution {
public:
    double myPow(double base, int power) 
    {
        // Corner Case
        if (power < 0) 
        { 
            base = 1 / base; 
            power = abs(power); 
        }
        
        // Main Logic to find the pow(base,power)
        double ans = 1;
        while(power > 0)
        {
            if (power % 2 == 0) 
            {
                // Power is even
                base = base * base;
                power = power / 2;
            }
            else 
            {
                // Power is odd
                ans = (ans * base);
                power--;
            }
        }
        return ans;
    }
};

// Approach 3: Fast Exponentiation
/*
Time Complexity: O(logn)
Space Complexity: O(1)
Where, n is power
*/

class Solution {
public:
    double myPow(double base, int power) 
    {
        // Corner case
        if (power < 0) 
        { 
            base = 1 / base; 
            power = abs(power); 
        }
        
        // Main Logic to find the pow(base,power)
        double ans = 1;
        while(power > 0)
        {
            if (power & 1) 
            {
                // Power is odd
                ans = ans * base;
            }
            // Power is even
            base = base * base;
            power = power >> 1;
        }
        return ans;
    }
};