// 📂 Print linked list

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

// Print linked list function
void printLL(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;    
}


int main()
{
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

    // Create head node
    Node* head = first;
    printLL(head);

    return 0;
}

/*
OUTPUT:
10->20->30->40->50->
*/