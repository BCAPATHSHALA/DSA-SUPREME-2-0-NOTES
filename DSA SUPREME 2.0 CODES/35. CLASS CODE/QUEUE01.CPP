// 2. Implementation of Queue using a Dynamic Array
#include<iostream>
using namespace std;

class Queue
{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        // Insertion 
        void push(int val){
            // Overflow Queue
            if(rear == size - 1){
                cout<< "Overflow Queue" << endl;
                return;
            }
            // Empty (Isse me bhool jata hu)
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            // Normal
            else{
                rear++;
                arr[rear] = val;
            }
        }

        // Deletion
        void pop(){
            // Underflow Queue
            if(front == -1 && rear == -1){
                cout<< "Underflow Queue" << endl;
                return;
            }
            // Single Element Queue (Isse me bhool jata hu)
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // Normal
            else{
                arr[front] = -1;
                front++;
            }
        }

        // Size of Queue
        int getSize(){
            // Empty Queue (Isse me bhool jata hu)
            if(front == -1 && rear == -1){
                return 0;
            }
            // Normal
            else{
                return (rear - front + 1);
            }
        }

        // Queue is empty or not
        bool isEmpty(){
            // Empty Queue
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        // Front element of queue
        int getFront(){
            // Empty Queue
            if(front == -1){
                // cout<< "No element in the queue, cannot give front element" << endl;
                return -1;
            }
            // Noraml
            else{
                return arr[front];
            }
        }

         // Rear element of queue
        int getRear(){
            // Empty Queue
            if(rear == -1){
                // cout<< "No element in the queue, cannot give rear element" << endl;
                return -1;
            }
            // Noraml
            else{
                return arr[rear];
            }
        }

        // Optional method just for testing purpose
        void print(){
            cout<< "Front Index: "<<front<<" | Rear Index: "<<rear<<endl;
            cout<< "Size of queue: "<< getSize() <<endl;
            cout<< "Printing Queue: ";
            for(int i=0; i<size; i++){
                cout<< arr[i] << " ";
            }
            cout<<endl<<endl;
        }

};

int main(){
    int size = 5;
    // Create Queue
    Queue q(size);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    q.push(60);
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();
    
    // ⭐ JAB front and rear array ke last index par honge
    // To iss code ki help se hum 800 ko insert nhi kar skte hai 
    // joki queue ki algorith ke according array ki 0th index par insert
    // hona chaiye
    // iska mtlb memory space waste ho rha hai -- Iska resolution Circular Queue hai
    q.push(800);
    q.print();

    q.pop();
    q.print();

    q.push(100);
    q.print();

    return 0;
}

/*
Front Index: -1 | Rear Index: -1
Size of queue: 0
Printing Queue: 0 0 0 0 0 

Front Index: 0 | Rear Index: 0
Size of queue: 1
Printing Queue: 10 0 0 0 0 
Front Index: 0 | Rear Index: 1
Size of queue: 2
Printing Queue: 10 20 0 0 0 

Front Index: 0 | Rear Index: 2
Size of queue: 3
Printing Queue: 10 20 30 0 0 

Front Index: 0 | Rear Index: 3
Size of queue: 4
Printing Queue: 10 20 30 40 0 

Front Index: 0 | Rear Index: 4
Size of queue: 5
Printing Queue: 10 20 30 40 50 

Overflow Queue
Front Index: 0 | Rear Index: 4
Size of queue: 5
Printing Queue: 10 20 30 40 50 

Front Index: 1 | Rear Index: 4
Size of queue: 4
Printing Queue: -1 20 30 40 50 

Front Index: 2 | Rear Index: 4
Size of queue: 3
Printing Queue: -1 -1 30 40 50 

Front Index: 3 | Rear Index: 4
Size of queue: 2
Printing Queue: -1 -1 -1 40 50 

Front Index: 4 | Rear Index: 4
Size of queue: 1
Printing Queue: -1 -1 -1 -1 50 

⭐Overflow Queue
Front Index: 4 | Rear Index: 4
Size of queue: 1
Printing Queue: -1 -1 -1 -1 50 

Front Index: -1 | Rear Index: -1
Size of queue: 0
Printing Queue: -1 -1 -1 -1 -1 

Front Index: 0 | Rear Index: 0
Size of queue: 1
Printing Queue: 100 -1 -1 -1 -1 

*/