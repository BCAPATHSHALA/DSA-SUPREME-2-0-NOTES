// Program 03: Sqrt of X (Leetcode-69)
class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s+(e-s)/2;
        int ans = -1;

        while(s <= e){
            // kya mid hi to ans nhi hai to return mid
            if(mid*mid == x){
                return mid;
            }
            // agar mid*mid greater then hai x se to left me chale jao
            else if(mid*mid > x){
                e = mid-1;
            }
            // agar mid*mid less then hai x se to ans me mid store karlo and right me chale jao
            else{
                ans = mid;
                s = mid+1;
            }
            mid= s+(e-s)/2;
        }
        return ans;
    }
};

/*
Example 01:
Input: x = 4
Output: 2

Example 02:
Input: x = 36
Output: 6

Example 03:
Input: x = 68
Output: 8

*/