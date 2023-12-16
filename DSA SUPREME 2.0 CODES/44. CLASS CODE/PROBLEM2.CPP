// 3. Insertion Operation of Heap Data Structure


/*
Insertion Operation:
Time Complexity: O(log N), Where N is number of elements in heap.
Space Complexity: O(capacity), Where capacity is constant.
*/

#include<iostream>
using namespace std;

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

        // Insertion Operation of Heap Data Structure
        void insertion(int val){
            if(size == capacity){
                cout<< "Heap Overflow" << endl;
                return;
            }

            // Size increase ho jayega (1-Based Indexing)
            size++;
            int index = size;
            arr[index] = val;

            // Take the value to its correct position
            while (index > 1)
            {
                int parentIndex = index/2;
                if(arr[index] > arr[parentIndex]){
                    // Swap kardo
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    // Loop ko stop kardo
                    break;
                }
            }
            
        }

        // Printing Heap
        void printHeap(){
            for (int i = 1; i <= size; i++)
            {
                cout<< arr[i] << " ";
            }
            cout<<endl;
        }
};

int main(){
    int capacity = 5;
    Heap h(capacity);

    // Insertion of element
    h.insertion(10);
    h.insertion(20);
    h.insertion(5);
    h.insertion(11);
    h.insertion(6);

    cout<< "Printing Heap" << endl;
    h.printHeap();
}

/*
Example 1:
Input: 10 20
Output: 20 10

Example 2:
Input: 10 20 5 11 6
Output: 20 11 5 10 6
*/