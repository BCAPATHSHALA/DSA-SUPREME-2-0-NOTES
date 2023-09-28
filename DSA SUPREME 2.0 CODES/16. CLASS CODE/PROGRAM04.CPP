// Program 04: Find and Replace Pattern (Leetcode-890)

/*
Approach:
Step 01: Create mapping and update string for string pattern 
Step 02: Create mapping and update string for all strings of string type array words and compare with mapped pattern
Step 03: Return vector ans

Time Complexity: ?

Space Complexity: ?
*/

class Solution {
public:
    // Create mapping and update string
    void createUpdateMapping(string& str) {
        // 1. find mappping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        // 2. update the string
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }

    // Find and replace pattern
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ans;

        // Step 01: Create mapping and update string for string pattern 
        createUpdateMapping(pattern);

        // Step 02: Create mapping and update string for all strings of string type array words
        for(string str: words){

            string tempStr = str;
            // Normalise tempStr
            createUpdateMapping(tempStr);

            //  compare b/w temp string and mapped pattern
            if(tempStr == pattern){
                // push correct str in ans
                ans.push_back(str);
            }
        }
        // Step 03: Return vector ans
        return ans;
    }
};


/*
Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/