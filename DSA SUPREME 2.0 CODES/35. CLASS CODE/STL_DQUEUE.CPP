// STL D-QUEUE
#include<iostream>
#include<deque>
using namespace std;

int main(){
    // Create D-Queue
    deque<int> dq;

    dq.push_back(10);

    cout<< "Front element: " << dq.front() << endl;
    cout<< "Rear element: " << dq.back() << endl;
    cout<< "Size of queue: " << dq.size() << endl << endl;
    
    dq.push_front(20);
    cout<< "Front element: " << dq.front() << endl;
    cout<< "Rear element: " << dq.back() << endl;
    cout<< "Size of queue: " << dq.size() << endl << endl;
    
    dq.pop_back();
    dq.pop_front();
    cout<< "Front element: " << dq.front() << endl;
    cout<< "Rear element: " << dq.back() << endl;
    cout<< "Size of queue: " << dq.size() << endl << endl;

    return 0;
}

/*
Front element: 10
Rear element: 10
Size of queue: 1

Front element: 20
Rear element: 10
Size of queue: 2

Front element: 10
Rear element: 20
Size of queue: 0
*/