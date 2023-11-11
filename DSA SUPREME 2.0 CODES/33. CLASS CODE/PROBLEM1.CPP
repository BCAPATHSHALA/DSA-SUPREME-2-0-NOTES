// 📂 Problem 1: Implementation of Two Stack in an Array

#include<iostream>
using namespace std;

class Stack
{
    public:
        int* arr;
        int size;
        int top1;
        int top2;

        Stack(int size){
            this->arr = new int[size];
            this->size = size;
            this->top1 = -1;
            this->top2 = size;
        }

        void push1(int data){
            if(top2 - top1 == 1){
                // No space available
                cout<<"OVERFLOW"<<endl;
                return;
            }
            else{
                top1++;
                arr[top1]=data;
            }
        }

        void push2(int data){
            if(top2 - top1 == 1){
                // No space available
                cout<<"OVERFLOW"<<endl;
                return;
            }
            else{
                top2--;
                arr[top2]=data;
            }
        }

        void pop1(){
            if(top1 == -1){
                // Stack 1 is empty
                cout<<"UNDERFLOW"<<endl;
                return;
            }
            else{
                arr[top1] = 0;
                top1--;
            }
        }

        void pop2(){
            if(top2 == size){
                // Stack 2 is empty
                cout<<"UNDERFLOW"<<endl;
                return;
            }
            else{
                arr[top2] = 0;
                top2++;
            }
        }

        // Optional method just for testing purpose
       void print()
       {
            cout<<"Top1: "<<top1<<endl;
            cout<<"Top2: "<<top2<<endl;
            cout<<"Stack: [ ";
            for(int i = 0; i<size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"]"<<endl<<endl;
       }
};

int main(){
    Stack st(6);
    st.print();
    
    st.push1(10);
    st.print();
    
    st.push1(20);
    st.print();
    
    st.push2(100);
    st.print();
    
    st.push2(200);
    st.print();
    
    st.push2(300);
    st.print();
    
    st.push1(30);
    st.print();
    
    st.push1(40);
    st.print();
    
    st.pop2();
    st.print();
    
    st.pop1();
    st.print();
    
    st.pop1();
    st.print();
    
    st.pop1();
    st.print();
    
    st.pop1();
    st.print();

    return 0;
}

/*
OUTPUT:
Top1: -1
Top2: 6
Stack: [ 0 0 0 0 0 0 ]

Top1: 0
Top2: 6
Stack: [ 10 0 0 0 0 0 ]

Top1: 1
Top2: 6
Stack: [ 10 20 0 0 0 0 ]

Top1: 1
Top2: 5
Stack: [ 10 20 0 0 0 100 ]

Top1: 1
Top2: 4
Stack: [ 10 20 0 0 200 100 ]

Top1: 1
Top2: 3
Stack: [ 10 20 0 300 200 100 ]

Top1: 2
Top2: 3
Stack: [ 10 20 30 300 200 100 ]

OVERFLOW
Top1: 2
Top2: 3
Stack: [ 10 20 30 300 200 100 ]

Top1: 2
Top2: 4
Stack: [ 10 20 30 0 200 100 ]

Top1: 1Top2: 4
Stack: [ 10 20 0 0 200 100 ]

Top1: 0
Top2: 4
Stack: [ 10 0 0 0 200 100 ]

Top1: -1
Top2: 4
Stack: [ 0 0 0 0 200 100 ]

UNDERFLOW
Top1: -1
Top2: 4
Stack: [ 0 0 0 0 200 100 ]
*/