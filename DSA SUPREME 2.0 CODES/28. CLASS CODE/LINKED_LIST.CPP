/*
📂 What is a node?
1. Nodes make up linked list
2. Each node is composed of data and a reference to the next node in the sequence.
3. Last node has a reference to null which indicates the end of the linked list.
4. Head node is starting node and Tail node is ending node of linked list.
5. Head and tail will have a null reference when linked list is empty.

Visualisation of a node

📂 What is a linked list?
1. It is a linear data structure
2. It is a collection of nodes
3. It is a sequence of non-continuous memory allocation
4. Linked list does not follow indexing to access the data
5. Linked lists use pointers (or references) to access the next node in the sequence, not direct physical memory addresses.
6. At runtime/Dynamically, We can shrink and grow size of linked list

Visualisation of linked list

📂 Why use of linked list?
1. Efficient use of memory:
Linked lists wastes memory less than array and vector.

2. Dynamic memory allocation:
Linked lists can be used when the number of elements is not known in advance.

📂 Types of linked list
1. Single
2. Double
3. Circular
4. Double circular

📂 Create link list and a node
*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node()
        {
            this->next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};


int main()
{
    // Create a node
    Node* head = new Node();

    // Assigning a value to the node
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    // Initializing the next pointer
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;    
    // Linked list create ho chuki hai

    return 0;
}