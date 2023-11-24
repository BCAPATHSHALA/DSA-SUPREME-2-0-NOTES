// 2. Reverse 'k' element in a queue ⭐

// APPROACH 01: USING STACK
// Time Complexity: O(N), Where N is numbers of elements in queue
// Space Complexity: O(N), Where N is numbers of elements in queue

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue<int> q){
    while (!q.empty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
    cout<<endl<<endl;
}

void reverseKEQueue(queue<int> &q, int K){
    stack<int> st;
    int N = q.size();

    // Step 1: push K element from queue to stack
    for(int i=0; i<K; i++){
        int frontElement = q.front();
        q.pop();
        st.push(frontElement);
    }

    // Step 2: push K element from stack to queue
    for(int i=K; i<N; i++){
        int topElement = st.top();
        st.pop();
        q.push(topElement);
    }

    // Step 3: pop and push first (N-K) elements from queue to queue
    for(int i=0; i<(N-K); i++){
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);
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
    reverseKEQueue(q,3);
    cout<<"After reversing queue: "<<endl;
    printQueue(q);   

    return 0;  
}

/*
Before reversing queue: 
10 20 30 40 50 60 
After reversing queue: 
30 20 10 40 50 60 
*/