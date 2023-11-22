/*
1. What is Queue?
Queue is linear data structure which operates in a FIFO (First in First out) principle.
Queue has two pointers are front and rear.

Note: 
All insertions are made at one end, called rear.
All deletions are made at one other end, called front.

2. STL Queue
    ⭐ create
    ⭐ insertion
    ⭐ deletion
    ⭐ size
    ⭐ empty
    ⭐ front
    ⭐ rear

Reference: 
https://en.cppreference.com/w/cpp/container/queue
https://cplusplus.com/reference/queue/queue/
*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Create Queue
    queue<int> q;

    // Insertion
    q.push(5);

    // Size
    cout<< "Size of Queue: " << q.size() << endl;

    // Empty
    if(q.empty()){
        cout<< "Queue is empty" << endl;
    }
    else{
        cout<< "Queue is not empty" << endl;
    }

    // Deletion
    q.pop();

    q.push(10);
    q.push(20);
    q.push(30);

    // Front
    cout<< "Front element of queue: " << q.front() << endl;

    // Rear
    cout<< "Rear element of queue: " << q.back() << endl;

    return 0;
}

/*
OUTPUT:
Size of Queue: 1
Queue is not empty
Front element of queue: 10
Rear element of queue: 30
*/