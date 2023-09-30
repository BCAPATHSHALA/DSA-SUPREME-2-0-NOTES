// HW 02: Find K-Closest Element (Leetcode-658)
class Solution {
public:
    // APPROACH 01: Two Pointer Approach (Maximum/Top to Minimum/Bottom)
    vector<int> twoPointerApp(vector<int>& arr, int k, int x){
        vector<int> ans;
        int n = arr.size();
        int start = 0;
        int end = n-1;

        // Step 01: Sorting with respect to diff of a and b
        while(end-start >= k){
            int a = arr[start];
            int b = arr[end];

            if(abs(x-a)<abs(x-b)){
                end--;
            }
            else if(abs(x-a)>abs(x-b)){
                start++;
            }
            else{
                end--;
            }
        }

        // Step 02: find nearly element of x
        for(int i=start;i<=end;i++){
            ans.push_back(arr[i]);
        }
        // return ans; or
        return vector<int>(arr.begin()+start,arr.begin()+end+1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointerApp(arr,k,x);
    }
};
/*
Time complexity: O(N-K), where N is length of arr and K is length of ans
Space complexity: O(1), no extra space used
*/


/*
Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Example 3:
Input: arr = [1,2,3,4,5], k = 4, x = 6
Output: [1,2,3,4]

Example 4:
Input: arr = [12,16,22,30,35,39,42,45,48,50,53,55,56], k = 4, x = 35
Output: [30,35,39,42]
*/