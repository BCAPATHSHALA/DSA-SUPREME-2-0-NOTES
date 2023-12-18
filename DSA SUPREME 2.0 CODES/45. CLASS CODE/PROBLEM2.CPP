// 2. C++ STL Priority Queue "MIN HEAP"

#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Create Min Heap (Min Priority Queue)
    priority_queue<int, vector<int>, greater<int>> minPQ;

    // Insertion
    minPQ.push(10);
    minPQ.push(20);
    minPQ.push(30);
    minPQ.push(40);
    minPQ.push(5);

    cout<< "Top (Root) element of Min Heap: " << minPQ.top() << endl;
    cout<< "Size of Min Heap: " << minPQ.size() << endl;
    cout<< "Min Heap is empty or not: " << minPQ.empty() << endl;

    // Deletion
    minPQ.pop();
    cout<< "Size of Min Heap: " << minPQ.size() << endl;

    return 0;
}

/*
OUTPUT:
Top (Root) element of Min Heap: 5
Size of Min Heap: 5
Min Heap is empty or not: 0
Size of Min Heap: 4
*/

/*
📂 Create Min Heap (Min Priority Queue)
........................................

Example: 
priority_queue<int, vector<int>, greater<int>> minPQ;

Explanation: 
priority_queue<data type, container type, comparator function> pq_name

1. Data Type: This is the data type of the elements that will be stored in the priority queue.
In this case, priority queue will store integers

2. Container Type: This is the container type used to store the elements internally.
In this case, the priority queue is implemented using this vector to store its elements.

3. Comparator Function: greater<int> makes the max priority queue act as a min priority queue

📂 Operations of priority queue:
Method	  Time Complexity	 Space Complexity
empty()	    O(1)	            O(1)
size()	    O(1)	            O(1)
top()	    O(1)	            O(1)
push()	    O(logN)	            O(1)
pop()	    O(logN)	            O(1)
*/