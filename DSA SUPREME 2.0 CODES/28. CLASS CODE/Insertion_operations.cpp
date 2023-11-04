// 📂Insertion operations
/*
(I) Insert node at the head
(II) Insert node at the tail
(III) Insert at any position
*/

/*
(I) Insert node at the head
We want to insert value 500 at head
Step 1: Create a new node
Step 2: temp->next = head
Step 3: head = temp
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

// (I) Insert node at the head
void insertAtHead(Node* &head, Node* &tail, int data)
{
    if(head == NULL){
        // Step 1: Create new node
        Node* newNode = new Node(data);
        
        // Step 2: Update head and tail
        head = newNode;
        tail = newNode;
    }
    else{
        // Step 1: Create a new node
        Node* newNode = new Node(data);

        // Step 2: Attache new node to head node
        newNode->next = head;

        // Step 3: Update the heade
        head = newNode;
    }
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
    Node* tail = fifth;
    cout << "Before Calling the insertAtHead()" << endl;
    printLL(head);
    cout << "After Calling the insertAtHead()" << endl;
    insertAtHead(head, tail, 500);
    printLL(head);

    return 0;
}

/*
OUTPUT:
Before Calling the insertAtHead()
10->20->30->40->50->
After Calling the insertAtHead()
500->10->20->30->40->50->
*/

/*
(II) Insert node at the tail
We want to insert value 500 at tail
Step 1: Create a new node
Step 2: tail->next = temp
Step 3: tail = temp
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

// (II) Insert node at the tail
void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(head == NULL){
        // Step 1: Create new node
        Node* newNode = new Node(data);
        
        // Step 2: Update head and tail
        // Ab single node a entire list me,
        // To head and tail ko newNode par point kardo
        head = newNode;
        tail = newNode;
    }
    else{
        // Step 1: Create a new node
        Node* newNode = new Node(data);

        // Step 2: Attache new node to head node
        tail->next = newNode;

        // Step 3: Update the tail
        tail = newNode;
    }
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
    Node* tail = fifth;
    cout << "Before Calling the insertAtHead()" << endl;
    printLL(head);
    cout << "After Calling the insertAtHead()" << endl;
    insertAtTail(head, tail, 500);
    printLL(head);

    return 0;
}

/*
OUTPUT:
Before Calling the insertAtHead()
10->20->30->40->50->
After Calling the insertAtHead()
10->20->30->40->50->500->
*/
