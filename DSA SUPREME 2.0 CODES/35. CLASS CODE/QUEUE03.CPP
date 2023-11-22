// 4. Implementation of Circular Double Ended Queue using a Dynamic Array
#include<iostream>
using namespace std;

class CDQueue
{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        CDQueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        // insertion and deletion from front
        void pushFront(int val){
            // Overflow 
             if((front == 0 && rear == size-1) || (rear == front-1)){
                cout<< "Overflow Queue" << endl;
                return;
            }
            // Empty queue
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }
            // ⭐Circular queue
            else if(front == 0 && rear != size - 1){
                front = size - 1;
                arr[front] = val;
            }
            // Normal
            else{
                front--;
                arr[front] = val;
            }
        }
        void popFront(){
            // Underflow
            if(front == -1 && rear == -1){
                cout<< "Underflow Queue" << endl;
                return;
            }
            // Single element queue
            else if(front==rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }        
            // Circular queue
             else if(front == size-1){
                arr[front] = -1;
                front = 0;
            }
            // Normal
            else{
                arr[front] = -1;
                front++;
            }
        }

        // insertion and deletion from rear
        void pushBack(int val){
            // Overflow 
             if((front == 0 && rear == size-1) || (rear == front-1)){
                cout<< "Overflow Queue" << endl;
                return;
            }
            // Empty queue
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            // Circular queue
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            // Normal
            else{
                rear++;
                arr[rear] = val;
            }
        }
        void popBack(){
           // Underflow
            if(front == -1 && rear == -1){
                cout<< "Underflow Queue" << endl;
                return;
            }
            // Single element queue
            else if(front==rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }        
            // ⭐Circular queue
             else if(rear == 0){
                arr[rear] = -1;
                rear = size - 1;
            }
            // Normal
            else{
                arr[rear] = -1;
                rear--;
            }
        }

        // Optional method just for testing purpose
        void print(){
            cout<< "Front Index: "<<front<<" | Rear Index: "<<rear<<endl;
            cout<< "Printing Queue: ";
            for(int i=0; i<size; i++){
                cout<< arr[i] << " ";
            }
            cout<<endl<<endl;
        }
};

int main(){
    int size = 5;
    // Creation of queue
    CDQueue dq(size);
    dq.print();
    
    dq.pushBack(10);
    dq.print();
    
    dq.pushFront(20);
    dq.print();
    
    dq.pushFront(30);
    dq.print();
    
    dq.pushBack(40);
    dq.print();
    
    dq.pushFront(50);
    dq.print();
    
    dq.pushFront(60);
    dq.pushBack(70);
    
    dq.popBack();
    dq.print();
    
    dq.popBack();
    dq.print();
    
    dq.popBack();
    dq.print();
    
    dq.popFront();
    dq.print();
    
    dq.popFront();
    dq.print();
    
    dq.popBack();

    return 0;
}

/*
Front Index: -1 | Rear Index: -1
Printing Queue: 0 0 0 0 0 

Front Index: 0 | Rear Index: 0
Printing Queue: 10 0 0 0 0 

Front Index: 4 | Rear Index: 0
Printing Queue: 10 0 0 0 20 

Front Index: 3 | Rear Index: 0
Printing Queue: 10 0 0 30 20 

Front Index: 3 | Rear Index: 1
Printing Queue: 10 40 0 30 20 

Front Index: 2 | Rear Index: 1
Printing Queue: 10 40 50 30 20 

Overflow Queue
Overflow Queue
Front Index: 2 | Rear Index: 0
Printing Queue: 10 -1 50 30 20 

Front Index: 2 | Rear Index: 4
Printing Queue: -1 -1 50 30 20 

Front Index: 2 | Rear Index: 3
Printing Queue: -1 -1 50 30 -1 

Front Index: 3 | Rear Index: 3
Printing Queue: -1 -1 -1 30 -1 

Front Index: -1 | Rear Index: -1
Printing Queue: -1 -1 -1 -1 -1 

Underflow Queue
Front Index: -1 | Rear Index: -1
Printing Queue: -1 -1 -1 -1 -1 

*/