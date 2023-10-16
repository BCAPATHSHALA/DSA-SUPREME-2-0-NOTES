// ✅HW 03: Longest Common Prefix (Leetcode-14)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i = 0;

        // Infinite loop is liye lagaya hai?-->
        // kyunki strs array contains different size of string
        while(true){
            char curr_ch = 0;
            for(auto str: strs){
                // Corner Case --> array index out of bound
                if(i>=str.size()){
                    curr_ch = 0;
                    break;
                }

                // Just started
                if(curr_ch == 0){
                    curr_ch = str[i];
                }
                // jab koi ek char match nhi karega to me for loop ko break kr doonga
                else if(str[i] != curr_ch){
                    curr_ch = 0;
                    break;
                }
            }

            // jab koi char common nhi hai tab while loop ko rok do
            if(curr_ch == 0){
                break;
            }

            // jab tak char common mil rhe hai tab tak ans me push karte raho
            ans.push_back(curr_ch);
            i++;
        }

        return ans;
    }
};

/*
Time Complexity: O(S)*O(N) = O(S*N), where N is length of array strs and S is length of smallest string of array strs
Space Complexity: O(S), where S is length of smallest string of array strs

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/