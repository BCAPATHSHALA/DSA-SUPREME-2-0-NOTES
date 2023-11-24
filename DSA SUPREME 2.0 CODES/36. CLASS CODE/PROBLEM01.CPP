// 1. Reverse a queue

// APPROACH 01: USING STACK
// Time Complexity: O(N), Where N is numbers of elements in queue
// Space Complexity: O(N), Where stack stores N elements from the queue.

// APPROACH 02: USING RECURSION
// Time Complexity: O(N)
// Space Complexity: O(N)
// Where N is numbers of elements in queue

#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

void printQueue(queue<int> q){
    while (!q.empty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
    cout<<endl<<endl;
}

void reverseQueueRE(queue<int> &q){
    // Base case
    if(q.empty()) return;

    // Ek step hum solve kar lenge
    int temp = q.front();
    q.pop();

    // Recursion solve kar lega
    reverseQueueRE(q);
    q.push(temp);
}

void reverseQueue(queue<int> &q){
    stack<int> st;

    // Step 1: one by one queue se element lelo and stack me insert kra do
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();

        st.push(frontElement);
    }

    // Step 2: one by one stack se element lelo and queue me insert kra do
    while(!st.empty()){
        int topElement = st.top();
        st.pop();

        q.push(topElement);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<"Before reversing queue: "<<endl;
    printQueue(q);   
    reverseQueueRE(q); 
    cout<<"After reversing queue: "<<endl;
    printQueue(q);   

    return 0;  
}

/*
Before reversing queue: 
10 20 30 40 50 60 
After reversing queue: 
60 50 40 30 20 10 
*/