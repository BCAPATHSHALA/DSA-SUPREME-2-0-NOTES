// Program 03: Valid Palindrome II (Leetcode-680)

/*
Approach: Two Pointer 
Step 01: when s[start] and s[end] are equals then start++ and end--
Step 02: when s[start] and s[end] are different then remove at most 1 character 
		  s[start] or s[end] then check palindrome for remaining string after removal
Step 03: then return true or false

Time Complexity: 0(N), where N is length of s
Space Complexity: 0(1), no extra space use
*/

class Solution {
public:
    // Palindrome Function
    bool checkPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    // Valid Palindrome II
    bool validPalindrome(string s) {
        int N = s.length();
        int start = 0;
        int end = N-1;

        while(start<end){
            // Step 01
            if(s[start]==s[end]){
                start++;
                end--;
            }
            // Step 02: 
            else{
                // Only one removal allowed
                // check palindrome for remaining string after removal
                
                //s[start] character --> remove
                bool ans1 = checkPalindrome(s, start+1, end);
                //s[end] character --> remove
                bool ans2 = checkPalindrome(s, start, end-1);

                // Step 03
                return ans1 || ans2;
            }
        }
        // Agar yanha tak pahunche ho to iska mtlb valid palindrome hai
        // iska mtlb --> zero removal hai
        return true;
    }
};

/*
Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true

Example 3:
Input: s = "abc"
Output: false
*/