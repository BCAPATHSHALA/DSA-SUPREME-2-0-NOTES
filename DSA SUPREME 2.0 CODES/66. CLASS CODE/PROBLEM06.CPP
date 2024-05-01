// 5. Optimization approach
// Problem 01: Minimum Window Substring (Leetcode-76)

/*
Problem Statement:
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
1. m == s.length
2. n == t.length
3. 1 <= m, n <= 10^5
4. s and t consist of uppercase and lowercase English letters.
 
Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // Invalid case
        int len1 = s.length();
        int len2 = t.length();
        int start = 0;
        if(len1 < len2) {
            return "";
        }

        // Valid case
        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        // Store freq of pattern string
        for(char ch: t) {
            tMap[ch]++;
        }

        // Initialise count variable
        // count variable means: yeh ek aisa character hai jo pattern and current window me present hai 
        int count = 0;
        int end = 0;
        while(end < s.length()) {

            // Update freq in sMap
            char ch = s[end];
            sMap[ch]++;
            if(sMap[ch] <= tMap[ch]) {
                // Valid character
                count++;
            }

            // Valid window
            if(count == len2) {
                // window found, jisme poora pattern existb krta h 
                //-> minimise
                // Minimise sirf usi case me karunga, jis case me 
                // 1. start index par jo character present h, 
                // 2. ya toh extra hai ya 
                // 3. aisa character jo pattern k andar hi nahi h, use bhi remove karo
                while(sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }

                // Ab answer nikalo
                int windowKaSize = end - start + 1;
                if(windowKaSize < ansLen) {
                    ansLen = windowKaSize;
                    ansIndex = start;
                }
            }
            // Invalid window
            end++;
        }

        if(ansIndex == -1) {
            return "";
        }
        else {
            return s.substr(ansIndex, ansLen);
        }
    }
};