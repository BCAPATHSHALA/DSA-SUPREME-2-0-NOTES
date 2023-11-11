// 📂 Problem 2: Valid Parentheses (Leetcode-20)

/*
PROBLEM STATEMENT:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "( () ( () ) )"
Output: true

Example 5:
Input: s = "("
Output: false

Example 6:
Input: s = ")"
Output: false

Time complexity: O(N), where N is size of string
Space complexity: O(N), where N is number of open brackets in stack
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i<s.length(); i++){
            char bracket = s[i];

            if(bracket == '(' || bracket == '{' || bracket == '['){
                // For open bracket-> just push
                st.push(bracket);
            }
            else{
                if(!st.empty()){
                    // For closing bracket
                    if( bracket == ')' && st.top() == '(' ){
                        st.pop();
                    }
                    else if( bracket == '}' && st.top() == '{' ){
                        st.pop();
                    }
                    else if( bracket == ']' && st.top() == '[' ){
                        st.pop();
                    }
                    else{
                        // No matching bracket
                        return false;
                    }
                }
                else{
                    // Hidden test cases
                    // single element string jo only ek 
                    // close bracket "]" "}" ")" contain karti ho 
                    // jiska mtlb hamesha invalid parenthese honge
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};