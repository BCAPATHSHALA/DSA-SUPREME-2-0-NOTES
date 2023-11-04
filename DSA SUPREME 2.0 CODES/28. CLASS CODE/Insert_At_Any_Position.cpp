// 📂 Insert in middle of linked list
// Step 1: Create a new node
// Step 2: Traverse the prev and curr to position
// Step 3: Attached prev to newNode
// Step 4: Attached newNode to curr


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

// Get the length of LL
int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

// (III) Insert at any position
void insertAtAnyPosition(Node* &head, Node* &tail, int data, int position)
{
    int length = getLength(head);
    
    if(position >= 1){
        insertAtHead(head, tail, data);
    }
    else if(position > length){
        insertAtTail(head, tail, data);
    }
    else{
        // Insert in middle of linked list

        // Step 1: Create a new node
        Node* newNode = new Node(data);

        // Step 2: Traverse the prev and curr to position
        Node* prev = NULL;
        Node* curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // Step 3: Attached prev to newNode
        prev->next = newNode;
        
        // Step 4: Attached newNode to curr
        newNode->next = curr;
    }   
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    printLL(head);
    insertAtAnyPosition(head, tail, 500, 51);
    printLL(head);
    return 0;
}