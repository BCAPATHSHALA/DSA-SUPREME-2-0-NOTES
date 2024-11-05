// 📂 6. Group Anagram (Leetcode-49)

/*
🧫 Problem Statement:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

🧫 Examples:
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

🧫 Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

// Solution 1: Using sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // <shorted str, original str>: <"eat", ["ate","eat","tea"]>
        
        // Step 1: Sort the each string to create the new unique entry with original strings in the map
        for(auto str: strs)
        {
            string s = str;
            sort(begin(s), end(s));
            mp[s].push_back(str);
        }

        // Step 2: Ab map se group anagram ko store karlo ek group me as result
        vector<vector<string>> result;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            result.push_back(it->second);
        }

        return result;
    }
};

// Solution 2: Using hash[256]
class Solution {
public:
    // Solve using hashing
    std::array<int, 256> hash(string s)
    {
        // Initialize the hash array with 0 and it's size is 256
        std::array<int, 256> hash = {0};

        // Create the hashing array for each vector of string as unique key for map
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int, 256>, vector<string>> mp; 

        // Step 1: Create the map 
        for(auto str: strs)
        {
            mp[hash(str)].push_back(str);
        }

        // Step 2: Ab map se group anagram ko store karlo ek group me as result
        vector<vector<string>> result;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            result.push_back(it->second);
        }

        return result;
    }
};