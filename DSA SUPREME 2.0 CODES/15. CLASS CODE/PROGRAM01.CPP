// Program 01: Remove All Adjacent Duplicates In String (Leetcode-1047)

/*
Approach:
Step 01: create a temp string
Step 02: compare input string's element with right most element of temp string
	- When both elements are different then push element in temp
    - When both elements are same then pop element from temp

Time Complexity: 0(N), where N is length of s
Space Complexity: 0(N), where N is length of temp
*/
class Solution {
public:
    string removeDuplicates(string s) {
        // Step 01: create a temp string
        string temp = "";
        int n = s.length();
        int i = 0;

        while(i<n){
            // Step 02: compare input string's element with right most element of temp string
            // When both elements are same then pop element from temp
            if(temp.length()>0 && s[i]==temp[temp.length()-1]){
                temp.pop_back();
            }
            // When both elements are different then push element in temp
            else{
                temp.push_back(s[i]);
            }
            i++;
        }
        return temp;
    }
};


/*
Example 1:
Input: s = "abbaca"
Output: "ca"

Example 2:
Input: s = "azxxzy"
Output: "ay"
*/