// Program 04: Palindromic Substrings (Leetcode-647)

/*
Approach: Two Pointer 
Step 01: check odd length's substring, how many substrings are palindrome 
Step 02: check even length's substring, how many substrings are palindrome 
Step 03: then return total number of substrings are palindrome (Odd + Even).

Time Complexity: 0(N), where N is length of s
Space Complexity: 0(1), no extra space use
*/

class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;

        // Jab tak substring palindrome ho tab tak me count increase karunga 
        // other wise loop  rok doonga
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {

        int totalCount = 0;
        int center = 0;

        while(center<s.length()){

            // Step 01: ODD 
            int oddCount = expand(s,center,center);

            // Step 02: EVEN
            int evenCount = expand(s,center,center+1);

            // Step 03: Total Count
            totalCount = totalCount + oddCount + evenCount;

            // Increase center
            center++;
        }
        // Return totalCount
        return totalCount;
    }
};

/*
Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/