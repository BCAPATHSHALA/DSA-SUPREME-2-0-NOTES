// 📂 PROBLEM 3: Insert at bottom of a stack

// Approach 1: Recursion and backtracking
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &element)
{
    // Base Case
    if(st.empty())
    {
        // insert element
        st.push(element);
        return;
    }

    // 1 case hum solve kar lege
    int temp = st.top();
    st.pop();

    // Recursion Call
    insertAtBottom(st, element);

    // Backtracking
    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    int element = 400;
    insertAtBottom(st, element);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}

/*
INPUT:
30 20 10
OUTPUT:
30 20 10 400 
*/