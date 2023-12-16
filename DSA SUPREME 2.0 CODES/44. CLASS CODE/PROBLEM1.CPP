/*
What is Heap Data Structure:
    A heap is a non-linear tree-based data structure where the tree is a complete binary tree.

Types of Heap Data Structure:
    A heap can be either a min heap or a max heap.
    In a max heap, the key of a parent node is greater than or equal to the key of its child node. 
    In a min heap, the key of a parent node is less than or equal to the key of its child node. 

Operations of Heap Data Structure:
    1. Insertion: process to insert an element in existing heap time complexity O(log N).
    2. Deletion: deleting the top (Root) element of the heap or the highest priority element, and 
    then organizing the heap and returning the element with time complexity O(log N).
    3. Heapify: a process of creating a heap from an array with time complexity O(N).
    4. Heap sort: sorting with time complexity O(N log N).

Application of Heap:
    Find min and max element with time complexity O(1).
*/


#include<iostream>
using namespace std;


// Create Heap Class
class Heap
{
    public:
        int *arr;
        int capacity;
        int size;

        Heap(int capacity){
            this->arr = new int[capacity];
            this->capacity = capacity;

            // Size = current number of elements in heap
            this->size = 0;
        }        
};

int main(){
    // Creation of heap
    int capacity = 5;
    Heap h(capacity);
}