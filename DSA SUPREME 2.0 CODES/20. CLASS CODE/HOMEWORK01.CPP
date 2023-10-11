// ✅Homework 01: Print Fibonacci series using iterative method
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int next = curr;
            curr = prev + curr;
            prev = next;
        }
        return curr;
    }
};