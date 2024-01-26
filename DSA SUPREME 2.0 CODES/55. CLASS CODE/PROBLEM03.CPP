// 3. Russian Doll Envelopes (Leetcode-354)

/*
Problem Statement:
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
In short, Maximum number of envelopes that can be put inside other bigger envelopes.

Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:
1. 1 <= envelopes.length <= 10^5
2. envelopes[i].length == 2
3. 1 <= wi, hi <= 10^5
*/

// ================== Approach 4: Space Optimization Approach ================== //

class Solution {
public:
        bool check(vector<int> curr , vector<int> prev){
        // Curr - bade wale dibbe ko represent krta hai
        // Prev - chotte wale dibbe ko represent krta hai
        if(curr[0] > prev[0] && curr[1] > prev[1]){
            return true;
        }
        else{
            return false;
        }
    }
    int solveUsingTabuOS(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        vector<int> currRow (n+1, 0);
        vector<int> nextRow (n+1, 0);

        // Loop row wise hi chalana hai mujhe
        for(int currIndex = n-1; currIndex >= 0; currIndex--){
            for(int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--){
                // Recursive call
                int include = 0;
                if(prevIndex == -1 || check(envelopes[currIndex], envelopes[prevIndex])){
                    include = 1 + nextRow[currIndex+1];
                }
                int exclude = 0 + nextRow[prevIndex+1];
                currRow[prevIndex+1] = max(include, exclude);
            }
            // Shift Karna Bhool Jata hu
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int ans = solveUsingTabuOS(envelopes);
        return ans;
    }
};

// ================== Approach 5: Solve Using Binary Search ================== //
class Solution {
public:
    // Own Comprator
    static bool com(vector<int> a , vector<int> b){
        if(a[0] == b[0]){
            // if Wi == Wj then sort envelop in decreasing order by height
            return a[1] > b[1];
        }
        // sort envelope in increasing order by width
        return a[0] < b[0];
    }

    // Apply longest increasing subsequence pattern on only height of envelop
    int solveUsingBS(vector<vector<int>> &envelopes){
        // Sort envelope in increasing order by width
        // and if Wi == Wj then sort envelop in decreasing order by height
        sort(envelopes.begin(), envelopes.end(), com);
        
        vector<int> ans;
        // initial state
        ans.push_back(envelopes[0][1]);

        for(int i=1; i<envelopes.size(); i++){
            if(envelopes[i][1] > ans.back()){
                // push new element when it is greater then of last element of ans
                ans.push_back(envelopes[i][1]);
            }
            else{
                // last element of ans is just greater then of new element to replace krdo
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                // replace last element of ans
                ans[index] = envelopes[i][1];
            }
        }
        // return length of ans
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = solveUsingBS(envelopes);
        return ans;
    }
};