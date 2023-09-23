// HW 10: Key Pair/Two Sum (GFG and Leetcode-1)
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// TWO SUM 
bool twoSum(vector<int> arr,int X){

    // Step 01: Sort the array
    sort(arr.begin(),arr.end());

    int N=arr.size();
    int s=0;
    int e=N-1;

    while(s<e){

        // Step 02
        if(arr[s]+arr[e]==X){
            return true;
        }
        // Step 03:
        // If pair sum is less than X, it means current pair is so small,
        // We have to move the starting index to right to consider larger pair.
        else if (arr[s]+arr[e]<X)
        {
            s++;
        }
        // Step 04:
        // If pair sum is greater than X, it means current pair is too large,
        // We have to move the ending index to left to consider smaller pair.
        else{
            e--;
        }        
    }
    return false;
}

int main(){
    vector<int> arr{1, 4, 45, 6, 10, 8};
    int X=16;

    bool ans = twoSum(arr,X);

    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}

/*
Time Complexity: O(NlogN)+O(N)=>O(NlogN), Where N is size of array
Space Complexity: O(1)
*/

/*
Example 01:
Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16

Example 02:
Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
*/
