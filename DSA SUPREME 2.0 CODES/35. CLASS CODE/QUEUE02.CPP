// 3. Implementation of Circular Queue using a Dynamic Array
#include<iostream>
using namespace std;

class CQueue
{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        CQueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        // Insertion
        void push(int val){
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

        // Deletion
        void pop(){
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
    
    // Ceate Queue
    CQueue q(size);
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
    
    q.pop();
    q.pop();
    q.pop();
    q.print();
    
    q.push(100);
    q.print();
    
    q.push(110);
    q.print();
    
    q.push(120);
    q.print();
    
    // ⭐ 
    q.push(130);
    q.print();
    
    return 0;
}

/*
Front Index: -1 | Rear Index: -1
Printing Queue: 0 0 0 0 0 

Front Index: 0 | Rear Index: 0
Printing Queue: 10 0 0 0 0 

Front Index: 0 | Rear Index: 1
Printing Queue: 10 20 0 0 0 

Front Index: 0 | Rear Index: 2
Printing Queue: 10 20 30 0 0 Front Index: 0 | Rear Index: 3
Printing Queue: 10 20 30 40 0 

Front Index: 0 | Rear Index: 4
Printing Queue: 10 20 30 40 50 

Overflow Queue
Front Index: 3 | Rear Index: 4
Printing Queue: -1 -1 -1 40 50 

Front Index: 3 | Rear Index: 0
Printing Queue: 100 -1 -1 40 50 

Front Index: 3 | Rear Index: 1
Printing Queue: 100 110 -1 40 50 

Front Index: 3 | Rear Index: 2
Printing Queue: 100 110 120 40 50 

⭐
Overflow Queue
Front Index: 3 | Rear Index: 2
Printing Queue: 100 110 120 40 50 
*/