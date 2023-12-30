DATE: 25-12-2023

## Problem 4: [Valid Palindrome (Leetcode-125)](https://leetcode.com/problems/valid-palindrome/)

[DOWNLOAD PDF NOTES](https://drive.google.com/drive/u/1/folders/1V1lszXbUO97guTtDgW8AWcIkryRB2uW9)

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a **palindrome**, or `false` otherwise.

### Examples

Example 1:

```bash
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

Example 2:

```bash
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

Example 3:

```bash
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
```

Example 4:

```bash
Input: s = "0P"
Output: false
Explanation: "0p" is not a palindrome.
```

### Constraints:

1. `1 <= s.length <= 10^5`
2. `s` consists only of printable ASCII characters.

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)
* [Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

### Solution 1

```cpp
/*
Brute Force Approach: USING TWO POINTER
Time complexity: O(N)
Space complexity: O(N)
Where N is the length of the input string
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    bool isPalindrome(string s) {

        // Step 1: Store alphanumeric characters include letters and numbers with T.C= O(N)
        string tempStr = "";
        for(int i=0; i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                tempStr+=s[i];
            }
        }

        // Step 2: convert string in lowercase using  transform() STL with T.C= O(N)
        transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower);

        // Step 3: apply two pointer approach to check the palindrome string or not with T.C= O(N/2)
        int start = 0;
        int end = tempStr.length()-1;

        while(start<=end){
            if(tempStr[start] == tempStr[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
```

### Solution 2

```cpp
/*
Optimal Approach: USING TWO POINTER
Time complexity: O(N)
Space complexity: O(1)
Where N is the length of the input string
Author: github.com/BCAPATHSHALA
*/
class Solution {
    public:
        bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
                }
            if(!isalnum(s[end])){
                end--;
                continue;
                }
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            else{
                // jab both character same mil jayenge
                start++;
                end--;
            }
        }
        return true;
    }
};
```

### Solution 2.1

```cpp
/*
Optimal Approach: USING TWO POINTER
Time complexity: O(N)
Space complexity: O(1)
Where N is the length of the input string
Author: github.com/BCAPATHSHALA
*/

class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           while(start < end && !isalnum(s[start])){
               start++;
            }
           while(start < end && !isalnum(s[end])){
               end--;
            }
           if(tolower(s[start]) != tolower(s[end])){
               return false;
           }
           else{
               // jab both character same mil jayenge
               start++;
               end--;
           }
       }
       return true;
}
};

/*
1. isalnum(ch) is used to check if the input value is either an alphabet or a number.
2. tolower(ch) is the character to be converted to lowercase
*/
```

### Solution 3

```cpp
/*
Optimal Approach: USING TWO POINTER
Time complexity: O(N)
Space complexity: O(1)
Where N is the length of the input string
Author: github.com/BCAPATHSHALA
*/
class Solution {
private:
    bool isUpperAlpha(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    bool isLowerAlpha(char c) {
        return (c >= 'a' && c <= 'z');
    }
    bool isNumeric(char c) {
        return (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        int N = s.length();
        int start = 0, end = N-1;
        while(start <= end) {
            while(start < end && !isUpperAlpha(s[start]) && !isLowerAlpha(s[start]) && !isNumeric(s[start])){
                start++;
            }
            while(start < end && !isUpperAlpha(s[end]) && !isLowerAlpha(s[end]) && !isNumeric(s[end])){
                end--;
            }
            if(start > end || tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

```
