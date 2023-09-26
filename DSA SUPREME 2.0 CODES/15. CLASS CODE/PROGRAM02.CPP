// Program 02: Remove All Occurrences of a Substring (Leetcode-1910)

/*
Approach:
Step 01: find part from s and remove part till end of last iteration of s
Step 02: return s

Time complexity of find() function and erase() function is O(N)

Time Complexity: 0(N), where N is length of s
Space Complexity: 0(1), no extra space use
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Step 01: Find part from s when part found then erase it from s
        while(s.find(part) != string::npos){
            // if inside loop, it means that part exists in s string
            s.erase(s.find(part),part.length());
        }
        // Step 02: return s
        return s;
    }
};

/*
Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
*/