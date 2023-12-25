DATE: 25-12-2023

## Problem 3: [Length of Last Word (Leetcode-58))](https://leetcode.com/problems/length-of-last-word/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given a string `s` consisting of words and spaces, return the length of the last word in the string.

A **word** is a maximal substring consisting of non-space characters only.

### Examples

Example 1:

```bash
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

Example 2:

```bash
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

Example 3:

```bash
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

### Constraints:

1. `1 <= s.length <= 10^4`
2. `s` consists of only English letters and spaces `' '`.
3. There is at least one word in `s`.

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

### Solution 1

```cpp
/*
Brute Force Approach:
Time complexity: O(N), traversing the entire string
Space complexity: O(N), stack and ans variable
Author: github.com/BCAPATHSHALA
*/
class Solution {
public:
    void trimString(string &s){
        // Trim the input string to remove leading and trailing spaces
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;   // Find the first non-space character
        while (j >= i && s[j] == ' ') j--;   // Find the last non-space character
        s = s.substr(i, j - i + 1);          // Extract the trimmed substring
    }
    int lengthOfLastWord(string s) {
        // Step 1: Trime the input string
        trimString(s);

        // Step 2: Store all words from string into stack
        int size = s.length();
        stack<string> st;
        string word = "";
        for(int i = 0; i<=size; i++)
        {
            if(s[i] == ' ' || i == size)
            {
                st.push(word);
                word="";
            }
            else
            {
                word+=s[i];
            }
        }

        // Step 3: Return length of top string of stack
        int lengthOfLastWord = st.top().length();
        return lengthOfLastWord;
    }
};
```

### Solution 2

```cpp
/*
Optimal Approach:
Time complexity: O(N), traversing the entire string
Space complexity: O(1)
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' '){
            i--;
        }

        int j = i;
        while (i >= 0 && s[i] != ' '){
            i--;
        }

        return j - i;
    }
};
```
