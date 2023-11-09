// 📂 PROBLEM 5: Insert in a sorted stack

// Approach 1: Recursion and backtracking
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st, int &element)
{
    // Base Case
    if(st.empty() || element > st.top())
    {
        // insert element
        st.push(element);
        return;
    }

    // 1 case hum solve kar lege
    int temp = st.top();
    st.pop();

    // Recursion Call
    insertSorted(st, element);

    // Backtracking
    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    int element = 25;
    insertSorted(st, element);


    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}

/*
INPUT:
Stack: 40 30 20 10
Element: 25

OUTPUT:
40 30 25 20 10 

INPUT:
Stack: 
Element: 25

OUTPUT:
25
*/