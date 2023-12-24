DATE: 24-12-2023

## Problem 2: [Reverse Words in a String (Leetcode-151))](https://leetcode.com/problems/reverse-words-in-a-string/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

### Examples

Example 1:

```bash
Input: s = "the sky is blue"
Output: "blue is sky the"
```

Example 2:

```bash
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

Example 3:

```bash
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

Example 4:

```bash
Input: s = "good"
Output: "good"
```

### Constraints:

1. `1 <= s.length <= 10^4`
2. `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
3. There is at least one word in `s`.

**Follow up:** If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Nvidia](https://leetcode.com/company/nvidia), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

### Solution 1

```cpp
/*
Brute Force Approach:
Time complexity: O(n), traversing the entire string
Space complexity: O(n), stack and ans variable
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

    string reverseWords(string s) {
        // Step 1: Trim the string
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

        // Step 3: Store and delete all elements from stack into string
        string ans = "";
        while(st.size() != 1){
            if(st.top().length() == 0){
                st.pop();
            }
            else{
                ans += st.top()+" ";
                st.pop();
            }
        }
        // Last word of string does not contain whitespace " "
        ans += st.top();
        return ans;
    }
};

```

### Solution 2

```cpp
/*
Optimal Approach:
Time complexity: O(n), traversing the entire string
Space complexity: O(1)
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

    string reverseWords(string s) {
        // Step 1: Trim the string
        trimString(s);

        // Step 2: Store all words from input string to ans string
        int size = s.length();
        int left = 0;
        int right = size-1;
        string word = "";
        string ans = "";

        while(left <= right)
        {
            char ch = s[left];
            if(ch != ' ')
            {
                word += s[left];
            }
            else
            {
                if(word != "")
                {
                    // Store first word first time
                    if(ans == "")
                    {
                        ans = word;
                        word = "";
                    }
                    else
                    {
                        ans = word + " " + ans;
                        word = "";
                    }
                }
            }
            left++;
        }

        // Store last word of input string to ans string
        if(word != "")
        {
            if(ans == "")
            {
                ans = word;
                word = "";
            }
            else
            {
                ans = word + " " + ans;
                word = "";
            }
        }
        return ans;
    }
};

```
