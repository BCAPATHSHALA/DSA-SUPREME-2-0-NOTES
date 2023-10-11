// ✅Program 01: Climbing stairs (Leetcode-70)

// Approach 1: Recursion ❌ TLE ❌
class Solution {
public:
    int climbStairs(int n) {
        // Base Case (Stop Knaha Par Hona Hai)
        if(n == 0 || n == 1){
            return 1;
        }

        // Recursive Relation/Call
        int ways = climbStairs(n-1)+climbStairs(n-2);
        return ways;        
    }
};