// HW 14: Missing Number (Leetcode-268)
class Solution {
public:    
    /*
    Approach 01:
    Step 01: Sum of nums
    Step 02: Sum of range [0,N]
    Step 03: Find missingNum = Step2 - Step1

    Time Complexity: O(N), where N is length of nums
    Space Complexity: O(1), no extra space used
    */
    int totalSum(vector<int>& nums){
        int n=nums.size();
        
        // Step 01: Sum of nums
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        // Step 02: Sum of range [0,N]
        int totalSum=(n*(n+1))/2;

        // Step 03: Find missingNum = Step2 - Step1
        int missingNum=totalSum-sum;

        return missingNum;
    }

    /*
    Approach 02:
    Step 01: XOR all nums[i] values
    Step 02: XOR all range items
    Step 03: return remaining range items

    Time Complexity: O(N), where N is length of nums
    Space Complexity: O(1), no extra space used
    */
    int xorApproach(vector<int>& nums){
        int n=nums.size();
        int ans = 0;

        // Step 01: XOR all nums[i] values
        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }

        // Step 02: XOR all range items
        for(int i=0; i<=n; i++){
            ans = ans ^ i;
        }

        // Step 03: return remaining range items
        return ans;
    }

    /*
    Approach 03:
    Step 01: Sorting nums
    Step 02: Compare nums[i] with indeces 
    Step 03: Return not matched index or nums size in the case of example [0,1] missing num=2

    Time Complexity: O(NlogN), where N is length of nums
    Space Complexity: O(1), no extra space used
    */
    int sortingApproach(vector<int>& nums){
        int n=nums.size();

        // Step 01: Sorting nums
        sort(nums.begin(), nums.end());

        // Step 02: Compare nums[i] with indeces 
        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            else{
                // Step 03: Return not matched index
                return i;
            }
        }

        // Step 03: Return numsSize N when all index matched with nums[i]
        return n;
    }

    int missingNumber(vector<int>& nums) {
        return sortingApproach(nums);        
    }
};

/*
Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/