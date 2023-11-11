// 📂 Problem 3: Remove Redundant Brackets

/*
Example 1:
Input: s = "(a+b)"
Output: false

Example 2:
Input: s = "(a+(b))"
Output: true

Example 3:
Input: s = "((a+b))"
Output: true

Example 4:
Input: s = "((a)+(b))"
Output: true

Example 5:
Input: s = "(a+b*c)"
Output: false

Example 6:
Input: s = "(a+(b*c))"
Output: false

Example 7:
Input: s = "((a)+(b*c))"
Output: true

Example 8:
Input: s = "((a+b)+(b+c))"
Output: false

Example 9:
Input: s = "("
Output: true

Example 10:
Input: s = ")"
Output: true

Example 11:
Input: s = "+"
Output: true

Time complexity: O(N), where N is size of string
Space complexity: O(N), where N is number of open brackets and operators in stack
*/

#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string &str){
    // Corner Case for single element string
    if(str.length() == 1){
        return true;
    }
    stack<char> st;

    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else if(ch == ')'){
            // Traverse the stack to count the operator and also remove operator from stack
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '/' || temp == '*'){
                    operatorCount++; // count operator
                }
                st.pop(); // remove operator
            }

            // Yanha tabhi pahuncha hu jab
            // Aapke stack ke top par ek opening bracket present hai
            // remove opening bracket
            st.pop();

            if(operatorCount == 0){
                return true; // Redundant Brackets Present Hai
            }
        }
    }

    // Yanha tabhi pahuncha hu jab
    // iska mtlb har ek bracket pair ke beech me
    // ek operator pakka mila hoga (operatorCount>0)
    return false;
}

int main(){
    string str = "((a+b)*(c+d))";
    bool ans = checkRedundant(str);

    if(ans){
        cout << "Redundant Brackets Present" << endl;
    }
    else{
        cout << "Redundant Brackets Not Present" << endl;
    }

    return 0;
}