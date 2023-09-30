// HW 02: Find K-Closest Element (Leetcode-658)
/*
APPROACH: 02 
Binary search and two pointer (Minimum/Bottom to Maximum/Top approach)
Step 01: Find lower bound value using Binary Search
Step 02: High => this is closest value of x
		  Low  => High - 1
Step 03: Expand the window from [Low, High] to K
			If arr[Low]-X > arr[High]-X then High++
			Else arr[Low]-X < arr[High]-X then Low-- till K==0
Step 04: Return ans
*/
class Solution {
public:
    // Step 01: Lower bound value using binary search
    int lowerBound(vector<int>& arr, int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = end; // -1 index bound error de skta hai when x=-1 ho ya x=invalid value 

        while(start<=end){
            int mid = (start + end)/2;
            if(arr[mid]>=x){
                ans = mid;
                end = mid-1;
            }
            else if(arr[mid]<x){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    // Two Pointer Approach + binary search
    vector<int> bs_method(vector<int>& arr, int k, int x){
        int h = lowerBound(arr,x);
        int l = h-1;

        // Sorting with respect to diff of a and b
        while(k--){
            if(l < 0){
                h++;
            }
            else if(h >= arr.size()){
                l--;
            }
            else if(abs(x-arr[l])>abs(x-arr[h])){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1,arr.begin()+h);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return bs_method(arr,k,x);
    }
};
/*
Time complexity: O(NlogN), where N is length of arr
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