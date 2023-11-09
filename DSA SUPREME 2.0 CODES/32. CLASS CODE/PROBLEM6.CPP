// 📂 PROBLEM 6: Sort a stack

// Approach 1: Recursion and backtracking
// Time Complexity: O(n^2)
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

void sortStack(stack<int> &st)
{
    // Base case
    if(st.empty())
    {
        return;
    }

    // 1 case hum solve kar lege
    int temp = st.top();
    st.pop();

    // Recursion call
    sortStack(st);

    // Backtracking
    insertSorted(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(5);
    st.push(12);
    st.push(8);
    st.push(9);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}

/*
INPUT:
Stack: 9 8 12 5 10

OUTPUT:
12 10 9 8 5 
*/