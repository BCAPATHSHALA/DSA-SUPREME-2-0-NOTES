// 4. Deletion Operation of Heap Data Structure

/*
Deletion Operation:
Time Complexity: O(log N), Where N is number of elements in heap.
Space Complexity: O(1), Where 1 is constant.
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

        // Deletion Operation of Heap Data Structure
        int deleteFromHeap(){
            int savedRoot = arr[1];

            // Step 1: Replace root element with last element
            arr[1] = arr[size];
            // Last element ko delete kardo --> means size-1 ho jayega
            size--;

            // Step 2: Ab root element ko uski correct position par rakh do
            int index = 1;
            while (index < size)
            {
                int leftIndex = 2*index;
                int rightIndex = 2*index+1;
                int largestIndex = index;

                // Now find -> larget index from three indeces
                // Check left index
                if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                    largestIndex = leftIndex;
                }
                // Check right index
                if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                    largestIndex = rightIndex;
                }
                // No changes in index -> loop break krdo
                if(index == largestIndex){
                    break;
                }
                else{
                    swap(arr[largestIndex], arr[index]);
                    index = largestIndex;
                }
            }

            return savedRoot;            
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

    int ans = h.deleteFromHeap();
    cout << "Deleted Element: " << ans << endl;
    cout<< "Printing Heap" << endl;
    h.printHeap();
}

/*
Example 1:
Input: 10 20 5 11 6

Output:
Before Deletion of Heap
20 11 5 10 6 
Deleted Element: 20
After Deletion of Heap
11 10 5 6 
*/