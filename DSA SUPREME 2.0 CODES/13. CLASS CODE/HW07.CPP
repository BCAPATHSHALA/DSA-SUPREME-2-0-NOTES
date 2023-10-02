// HW 07: Aggressive Cows (GFG & Code studio)
class Solution {
public:

    // Predicate Function
    bool isPossibleSol(int n,int k,vector<int> &stalls,int mid){
        int cases = 1; 
        int lastPos = stalls[0]; // we already place it at the first available slot i.e stalls[0]
        
        for(int i=1; i<n; i++){
            if(stalls[i] - lastPos >= mid){
               cases++;
               if(cases == k){
                return true;
               }
               // reset last position
               lastPos = stalls[i];
            }
        }
        return false;
    }

    // Binary Search
    int BinarySearch(int n, int k, vector<int> &stalls,int highestMinDis){
        int start = 0;
        int end = highestMinDis;
        // Mid ka mtlb hai --> It is only Lowest Min Distance Position 
        // iska mtlb hai ki mid se kam distance hone par 100% possibility hai ki two cow lad skti hai
        int mid = start + (end - start)/2;
        // Ans ka mtlb yeh hai --> ans belonges to range of [mid,highestMinDis]
        int  ans = -1; 
        
        while(start<=end){
            // Step 04: This predicate Function
            if(isPossibleSol(n,k,stalls,mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        
        return ans;
    
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Step 01: Sort the array
        sort(stalls.begin(), stalls.end());
        
        // Step 02: Find Highest Minmum Distance
        // Me yanha par Jo distance nikaalunga wo ek aisa distance hoga jis distance par two cow 
        // kabhi bhi nhi lad skti hai
        int highestMinDis = stalls[n-1] - stalls[0];
        
        // Step 03: Now, Applying Binary Search on search space
        int ans = BinarySearch(n,k,stalls,highestMinDis);
        
        return ans;
        
    }
};

/*
Problem Statement:
You are given an array consisting of n integers which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. 
You are given the task of assigning stalls to k cows such that the minimum distance 
between any two of them is the maximum possible.

---------------------------------------------------------------------------------------------------------------
Observation:
stall ki position = stalls[ith]
stalls array ka size = n
number of cows = k
mujhe find kya karna hai = minimum distance between two of them is maximum distance possible
---> iska mtlb yeh hai ki -- Pahle hame har ek case me two cows ke beech ka minimum distance find karna hai 
     uske baad hame minimum distances me se maximum distance as a final ans batana hai.

---------------------------------------------------------------------------------------------------------------
Example 01:
Input: n=5 , k=3, stalls = [1 2 4 8 9]
Output: 3

---------------------------------------------------------------------------------------------------------------
Explanation:
1st stall ki position = stalls[0] = 1
2nd stall ki position = stalls[1] = 2
3rd stall ki position = stalls[2] = 3
4rt stall ki position = stalls[3] = 4
5th stall ki position = stalls[4] = 5

The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.

---------------------------------------------------------------------------------------------------------------
OPTIMAL APPROACH: Define search space and predicate function 
Step 01: Sort the array
Step 02: Find Highest Minmum Distance to create search space's end point
Step 03: Now, Applying Binary Search on search space BinarySearch()
Step 04: create predicate function isPossibbleSol()

---------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*log(end)), Here N is size of array stalls and end is the highestMaxDis
Space Complexity: O(1), no extra space used

---------------------------------------------------------------------------------------------------------------
Resource: https://practice.geeksforgeeks.org/problems/aggressive-cows/0