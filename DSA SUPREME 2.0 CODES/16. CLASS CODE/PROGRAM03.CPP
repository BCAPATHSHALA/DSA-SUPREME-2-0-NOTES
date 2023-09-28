// Program 03: Custom Sort String (Leetcode-791)
/*
Approach:
Step 01: Use custom comparator to arrange character of string s according to string order
Step 02: in custom comparator, find character's position of s string and compare b/w both a and b positions in string order
Step 03: Return arranged string s

Time Complexity: O(L) + O(NlogN) = (NlogN), where 
L is the length of the string order
N is a length of string s

Space Complexity: O(1), where no extra space used
*/

class Solution {
public:
    // Step 02: in custom comparator, find character's position of s string in string order
    static string orderStr;
    static bool compare(char ch1, char ch2){
        char a = orderStr.find(ch1);
        char b = orderStr.find(ch2);

        // Compare b/w both a and b positions to arrange character in string s
        // If a > b = b pahle ayega or bad me a ayega
        // If a < b = a pahle ayega or bad me b ayega

        // output string
        return a < b;
    }

    string customSortString(string order, string s) {

        orderStr = order;

        // Step 01: Use custom comparator to arrange character of string s according to string order
        sort(s.begin(), s.end(), compare);

        // Step 03: Return arranged string s
        return s;
    }
};
string Solution::orderStr;

/*
Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "cbafg", s = "abcd"
Output: "cbad"
*/