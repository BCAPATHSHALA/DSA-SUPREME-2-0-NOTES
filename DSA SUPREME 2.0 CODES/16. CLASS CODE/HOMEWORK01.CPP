// ✅HW 01: Valid Anagram (Leetcode-245)
class Solution {
public:
    bool isAnagram(string s, string t) {

        int freqTable[256] = {0};

        // Updating freqTable by 's' string
        for(int i=0; i<s.size(); i++){
            freqTable[s[i]]++;
        }

        // Again, Updating freqTable by 't' string
        for(int i=0; i<t.size(); i++){
            freqTable[t[i]]--;
        }

        // Comparing each elements of freqTable are zero or not
        for(int i=0; i<256; i++){
            if(freqTable[i] != 0){
                // Agar ek abhi element not equal to zero hai to invalid anagram hai
                return false;
            }
        }
        // Agar all elements equal to zero hai to valid anagram hai
        return true;
    }
};

/*
Time Complexity: O(N+M), where N is length of 's' and M is length of 't'
Space Complexity: O(1), no extra space used

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

