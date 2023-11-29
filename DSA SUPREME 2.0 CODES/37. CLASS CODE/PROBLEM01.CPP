// 1. First Non Repeating/Unique Character in a String (Leetcode-387)

/*
Problem Statement:
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1. 1 <= s.length <= 10^5
2. s consists of only lowercase English letters.

Time Complexity: O(N^2), Where N is length of string
Space Complexity: O(N), Where queue stores N number of characters
*/

#include<iostream>
#include<deque>
#include<string>
using namespace std;

void firstUniqueChar(string s){
    deque<int> q;
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        // I -> picking current character from string
        char ch = s[i];

        // II -> storing the frequency of current character to array
        freq[ch - 'a']++;

        // III -> inserting the index of current character to queue
        q.push_back(i);

        
        // IV -> Ans find kro: Unique character hai ya nhi
        while(!q.empty()){
            // I -> picking the front value from queue
            char frontChar = s[q.front()];

            // II -> going to freq table to check the frontChar is unique or not
            if(freq[frontChar - 'a'] > 1){
                // Character is repeating-> no ans
                q.pop_front();
            }
            else{
                // Character is not repeating-> ans
                cout<< frontChar << " ";
                break;
            }
        }

        // Agar koi bhi ans nhi mila hai 
        // iska mtlb queue empty ho chuka hai
        if(q.empty()){
            cout<< '#' << " ";
        }    
    }
}


int main(){
    string s = "ababc";
    firstUniqueChar(s);
    return 0;
}


// LEETCODE PROBLEM SOLUTION CODE
class Solution {
public:
    int firstUniqChar(string s){
        deque<int> q;
        int freq[26] = {0};
        int ans = -1;

        for (int i = 0; i < s.length(); i++)
        {
            // I -> picking current character from string
            char ch = s[i];

            // II -> storing the frequency of current character to array
            freq[ch - 'a']++;

            // III -> inserting the index of current character to queue
            q.push_back(i);

            
            // IV -> Ans find kro: Unique character hai ya nhi
            while(!q.empty()){
                // I -> picking the front value from queue
                char frontChar = s[q.front()];

                // II -> going to freq table to check the frontChar is unique or not
                if(freq[frontChar - 'a'] > 1){
                    // Character is repeating-> no ans
                    q.pop_front();
                }
                else{
                    // Character is not repeating-> ans
                    ans = q.front();
                    break;
                }
            }

            // Agar koi bhi ans nhi mila hai 
            // iska mtlb queue empty ho chuka hai
            if(q.empty()){
                ans = -1;
            }    
        }
        return ans;
    }
};