// 📂 PROBLEM 2: Middle element of a stack

// Approach 1: Recursion and backtracking
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int pos, int &ans)
{
    // Base Case
    if(pos == 1)
    {
        // ans = middle element
        ans = st.top();
        return;
    }

    // 1 case hum solve kar lege
    pos--;
    int temp = st.top();
    st.pop();

    // Recursion Call
    solve(st, pos, ans);

    // Backtracking
    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{   
    // Empty Stack
    if(st.empty()){
        return -1;
    }

    // Non Empty Stack
    int size = st.size();
    int pos = 0;

    if(size & 1)    {
        // ODD STACK
        pos = (size/2)+1;
    }
    else{
        // EVEN STACK
        pos = size/2;
    }

    int ans = -1;
    solve(st, pos, ans);
    return ans;    
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int mid = getMiddleElement(st);
    cout<<"Middle element: "<< mid << endl;

    return 0;
}