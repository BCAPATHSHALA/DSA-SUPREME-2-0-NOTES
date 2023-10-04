// DOUBT 02: Remove All Occurrences of a Substring (Leetcode-1910)
class Solution {
public:
    // APPROACH 01: Without erase method
    string removePart1(string s, string part){
        while(true){
            int found = s.find(part);
            if(found == string::npos) break;

            // We have to remove the part
            string LP = s.substr(0,found);
            string RP = s.substr(found + part.size(), s.size());

            // Concat both part LP and RP
            s = LP + RP;
        }
        // Step 02: return s
        return s;
    }

    // APPROACH 02: With erase method
    string removePart2(string s, string part){
        while(s.find(part) != string::npos){
            s.erase(s.find(part),part.length());
        }
        return s;
    }

    // Remove occurrences from substring s
    string removeOccurrences(string s, string part) {
        return removePart2(s,part);
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