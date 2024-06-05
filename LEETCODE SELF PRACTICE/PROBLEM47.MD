DATE: 05-06-2024

## Problem 47: [ Find Common Characters (Leetcode-1002) ](https://leetcode.com/problems/find-common-characters)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a string array `words`, return an array of all characters that show up in all strings within the `words` *(including duplicates)*. You may return the answer in **any order**.

## Examples

Example 1:

```bash
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
```

Example 2:

```bash
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
```

## Constraints:

1. `1 <= words.length <= 100`
2. `1 <= words[i].length <= 100`
3. `words[i]` consists of lowercase English letters.

**Companies**:  
[TripAdvisor](https://leetcode.com/company/tripadvisor)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Solution 1

```cpp
// Optimal Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
// Author: github.com/BCAPATHSHALA

class Solution {
public:
    void fillCount(string word, int count[26]){
        for(char &ch: word){
            count[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        int count[26] = {0};

        // Step 1: fill the freq of first word's char of words as count
        fillCount(words[0], count);

        // Step 2: fill the freq of remaning word's char of words as temp
        for(int i = 1; i < n; i++){
            int temp[26] = {0};
            fillCount(words[i], temp);

            // Step 2.1: now update the count with common character of both count and temp
            for(int j = 0; j < 26 ; j++){
                count[j] = min(count[j], temp[j]);
            }
        }

        // Step 3: store all common char in result
        for(int i = 0; i < 26; i++){
            int c = count[i];
            while(c--){
                // Character representing ith index - i+'a'
                result.push_back(string(1, i+'a'));// string(length, char)
            }
        }

        // Step 4: return the expected output
        return result;
    }
};
```
