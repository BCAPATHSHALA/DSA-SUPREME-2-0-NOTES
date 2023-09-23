// HW 12: Maximum Average Subarray 1 (Leetcode-643)

// Method 01: Brute force solution
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        int maxSum = INT_MIN;
        int i = 0, j=k-1;

        while(j<N){
            int sum = 0;
            for(int x=i;x<=j;x++){
                sum = sum + nums[x];
            }
            maxSum = max(maxSum, sum);
            j++, i++;
        }

        
        // Find maximum average of maximum sum
        double maxAvg = maxSum/(double)k;
        return maxAvg;
    }
};
/*
Time Complexity: O(N^2), Where N is size of array
Space Complexity: O(1)
*/

// Optimal Solution: Sliding Window Approach
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();        
        int i = 0, j=k-1;

        int sum = 0;
        // Step 01: Find sumof first window
        for(int x=i;x<=j;x++){
            sum = sum + nums[x];
        }
            
        int maxSum = sum; 
        // Step 02: Find maxSum
        // Me pahle hi check kar loonga ki j out of bound to nhi ho rha hai
        j++; // pahle aap j ko use karlo uske baad increment by one kardo
        while(j<N){
            sum = sum - nums[i++];
            sum = sum + nums[j++];
            maxSum = max(maxSum, sum);
        }       

        // Find maximum average of maximum sum
        double maxAvg = maxSum/(double)k;
        return maxAvg;
    }
};

/*
Time Complexity: O(N), Where N is size of array
Space Complexity: O(1)
*/

/*
Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000 26.50000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

Example 3:
Input: nums = [1,12,-5,-6,50,3], k = 2
Output: 26.50000
*/