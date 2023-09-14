// Program 06: Peak element/index in a mountain array (Leetcode-852)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int start=0;
        int end=n-1;

        // Termination condition
        while(start<end){
            int mid=start+(end-start)/2;

            if(arr[mid]>arr[mid+1]){
                // Me B line par hu 
                // Yaa me PEAK par hu
                end=mid;
            }
            else if(arr[mid]<arr[mid+1]){
                // Me A line par hu
                // And PEAK right me exist karta hai
                start=mid+1;
            }
        }

        return start;
        
    }
};

/*
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1

Example 4:
Input : arr[] = [10,20,30,90,70,60,50,40]
Output : 3

Example 5:
Input : arr[] = [10,20,50,40,30]
Output : 2
*/