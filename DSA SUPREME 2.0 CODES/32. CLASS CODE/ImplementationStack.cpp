// 📂 Implementation of a stack using dynamic array

/*
	2. Stack implementation using dynamic array
	   - push() method
	   - pop() method
	   - isEmpty() method
	   - getTop() method
	   - getSize() method
	   - Important corner cases: overflow and underflow 
*/

#include<iostream>
using namespace std;

class Stack
{
    public:
        int* arr;
        int size;
        int top;

        Stack(int size)
        {
            arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        // push() method
       void push(int data)
       {
            if(top == size - 1)
            {
                cout<<"Stack is overflow"<<endl;
                return;
            }
            else
            {
                top++;
                arr[top] = data;
            }
       }

       // pop() method
       void pop()
       {
            if(top == -1)
            {
                cout<<"Stack is underflow"<<endl;
                return;
            }
            else
            {
                top--;
            }
       }

       // isEmpty() method
       bool isEmpty()
       {
            if(top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
       }

       // getTop() method
       int getTop()
       {
            if(top == -1)
            {
                return -1;
            }
            else
            {
                return arr[top];
            }
       }

       // getSize() method
       int getSize()
       {
           return top+1;
       }

       // Optional method just for testing purpose
       void print()
       {
            cout<<"Top: "<<top<<endl;
            cout<<"Top element: "<<getTop()<<endl;
            cout<<"Size of stack: "<<getSize()<<endl;
            if(isEmpty())
            {
                cout<<"Empty Stack"<<endl;
            }
            else
            {
                cout<<"Not Empty Stack"<<endl;
            }
            cout<<"Stack: [ ";
            for(int i = 0; i<getSize(); i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"]"<<endl<<endl;
       }
};

int main()
{
    // Creation
    Stack st(8);

    // Insertion
    st.push(10);
    st.print();
    
    st.push(20);
    st.print();
    
    // Deletion 
    st.pop();
    st.print();
    
    st.pop();
    st.print();

    return 0;
}

/*
OUTPUT:
Top: 0
Top element: 10
Size of stack: 1
Not Empty Stack
Stack: [ 10 ]

Top: 1
Top element: 20
Size of stack: 2
Not Empty Stack
Stack: [ 10 20 ]

Top: 0
Top element: 10
Size of stack: 1
Not Empty Stack
Stack: [ 10 ]

Top: -1
Top element: -1
Size of stack: 0
Empty Stack
Stack: [ ]
*/