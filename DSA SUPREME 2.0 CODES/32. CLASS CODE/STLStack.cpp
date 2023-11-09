// 📂 STL STACK

/*
What is stack?
1. Stack is a linear data structure where insertion or deletion of elements is done 
from only one side/end which is called top of the stack.

2. LIFO: Last In First Out

Important Operation of a Stack:
push() method: insert new element to top
pop() method: delete element from top
empty() method: return true or false value
top() method: return top element
size() method: return size of stack

3. Resources to master the stack
https://cplusplus.com/reference/stack/stack/
https://en.cppreference.com/w/cpp/container/stack

*/

#include<iostream>
#include<stack> 
using namespace std;

int main(){
    // Create Stack
    stack<int> st;

    // Insertion
    st.push(1);
    st.push(2);
    st.push(3);

    // Size of stack
    cout<<"Size of stack: "<<st.size()<<endl;

    // Deletion
    st.pop();

    // Check empty
    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    // Top element
    cout<<"Top element: "<<st.top()<<endl;

    return 0;
}

/*
OUTPUT:
Size of stack: 3
Stack is not empty
Top element: 2
*/