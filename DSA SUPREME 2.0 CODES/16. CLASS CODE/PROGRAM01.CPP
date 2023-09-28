// Program 01: Decode the Message (Leetcode-2325)

/*
Approach:
Step 01: Create mapping for key
Step 02: Use mapping to decode the message
Step 03: Return decoded message

Time Complexity: O(M)+ O(N) = O(M+N), where 
M is a legth of key string and 
N is a length of message string

Space Complexity: O(1) + O(N) = O(N), where 
O(1) -> mapping size is constant
O(N) -> ans store the decode message
*/

class Solution {
public:
    string decodeMessage(string key, string message) {
        // Step 01: Create mapping for key
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: key){
            if(ch != ' ' && mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }

        // Step 02: Use mapping to decode the message
        string ans;
        for(auto ch: message){
            if(ch == ' '){
                ans.push_back(' ');
            }
            else{
                char decodeChar = mapping[ch];
                ans.push_back(decodeChar);
            }
        }
        // Step 03: Return decoded message
        return ans;
    }
};

/*
Example 01:
Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"

Example 02:
Input: key = "the dogt", message = "doge"
Output: "defc"

Example 03:
Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
Output: "the five boxing wizards jump quickly"
*/