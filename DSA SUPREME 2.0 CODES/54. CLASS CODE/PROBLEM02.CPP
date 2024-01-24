// 2. Longest Palindrome Subsequence (Leetcode-516)

/*
Problem Statement:
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting 
some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
1. 1 <= s.length <= 1000
2. s consists only of lowercase English letters.
*/

//! Note: Other 3 remaining approaches are same as problem01
// ================== Approach 4: Space Optimization Approach ================== //

class Solution {
public:
       int solveUsingTabuOS(string &a, string &b, int i, int j) {
        vector<int> curr (a.length()+1, 0);
        vector<int> next (a.length()+1, 0);

        for(int j = b.length()-1; j >= 0; j--){
            for(int i = a.length()-1; i >= 0; i--){
                // Recursive call
                int ans = 0;
                if(a[i] == b[j]) {
                    // Does match the subsequence character
                    ans = 1 + next[i+1];
                }
                else {
                    // Does not match the subsequence character
                    ans = 0 + max(next[i], curr[i+1]);
                }
                curr[i] = ans;
            }
            // shifting
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string text1) {
        string text2 = text1;
        reverse(text1.begin(), text1.end());
        int i = 0;
        int j = 0;
        int ans = solveUsingTabuOS(text1, text2, i, j);
        return ans;
    }
};