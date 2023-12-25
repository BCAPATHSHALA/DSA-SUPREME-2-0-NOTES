#include <iostream>
#include <queue>

// Custom comparison function for the max heap
struct Compare {
    bool operator()(int a, int b) {
        // Returns false if a comes before b in the ordering
        return a < b;
    }
};

int main() {
    // Creating a max heap of integers with the custom comparison function
    std::priority_queue<int, std::vector<int>, Compare> pq;

    // Inserting elements into the max heap
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    // Printing elements from the max heap
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    
    return 0;
}

/*
INPUT: 5 2 8 1
OUTPUT: 8 5 2 1 (MAX HEAP)
*/