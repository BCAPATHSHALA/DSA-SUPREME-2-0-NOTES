// 📂 PROBLEM 1: Reverse string using stack

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string str = "BABBAR";

    stack<char> st;

    // Step 1: Push each character of string into stack
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        st.push(ch);
    }

    // Step 2: Pop element from stack
    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;
}

/*
OUTPUT:
R A B B A B 
*/