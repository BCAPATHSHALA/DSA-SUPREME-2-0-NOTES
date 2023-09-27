// HW 01: Remove All Adjacent Duplicates in String II (Leetcode-1209)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int>vec(s.length(),0);
        int i=0;
        
        while(i<s.length())
        {
            if(i==0||s[i]!=s[i-1])
                vec[i]=1;
            else
            {
                vec[i]=vec[i-1]+1;
                if(vec[i]==k)
                {
                    i-=k;
                    s.erase(i+1,k);
                }
            } 
            i++;
        }
        return s;
    }
};

/*
Time Complexity: 0(N), where N is length of s
Space Complexity: 0(N), where N is length of vector
*/

/*
Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Example 4:
Input: s = "eeek", k = 3
Output: "k"
*/