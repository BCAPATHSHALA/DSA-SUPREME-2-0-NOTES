// ✅HW 02: Reverse Only Letters (Leetcode-917)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.size()-1;

        while(start <= end){
            if(isalpha(s[start]) && isalpha(s[end])){
                swap(s[start], s[end]);
                start++, end--;
            }
            else if(!isalpha(s[start])){
                start++;
            }
            else if(!isalpha(s[end])){
                end--;
            }
        }
        return s;
    }
};
/*
Time Complexity: O(N/2) = O(N), where N is length of 's'
Space Complexity: O(1), no extra space used

Example 1:
Input: s = "ab-cd"
Output: "dc-ba"

Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
*/