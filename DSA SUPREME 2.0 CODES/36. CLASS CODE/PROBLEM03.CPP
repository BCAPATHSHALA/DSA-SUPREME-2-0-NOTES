// 3. Interleave first and second half of a queue


// APPROACH 01: ITERATIVE 
// Time Complexity: O(N), Where N is numbers of elements in queue
// Space Complexity: O(N), Where N is numbers of elements in queue

#include<iostream>
#include<queue>
using namespace std;

void printQueue(queue<int> q){
    while (!q.empty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
    cout<<endl<<endl;
}

void interLeaveQueue(queue<int> &first){
    queue<int> second;
    int size = first.size();

    // Step 1: break queue into half
    for(int i=0; i<(size/2); i++){
        int fFront = first.front();
        first.pop();
        second.push(fFront);
    }

    // Step 2: merge both half
    while(!second.empty()){
        int sFront = second.front();
        second.pop();
        first.push(sFront);

        int fFront = first.front();
        first.pop();
        first.push(fFront);
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
    interLeaveQueue(q);
    cout<<"After reversing queue: "<<endl;
    printQueue(q);   

    return 0;  
}

/*
Before interleave queue: 
10 20 30 40 50 60 
After interleave queue: 
10 40 20 50 30 60
*/