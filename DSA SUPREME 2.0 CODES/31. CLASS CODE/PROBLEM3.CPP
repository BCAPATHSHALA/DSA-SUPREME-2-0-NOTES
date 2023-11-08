// 📂 Problem 3: Remove loop (GFG)

/*
Approach 1: Fast and slow algorithm
Time Complexity: O(N)
Space Complexity: O(1)
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

// Print linked list
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


// 📂 Delete a node from the head
void deletefromHead(Node* &head, Node* &tail)
{    
    // Step 1: Set Corner Cases: Empty LL and Single Element LL
    if(head == NULL){ 
        // Empty LL
        cout << "Can't delete, because of empty linked list" << endl;
        return;
    }
    if(head == tail){ 
        // Single Element LL
        Node* temp = head;
        delete temp;
        head->next = NULL;
        tail->next = NULL;
        return;
    }
    
    // Step 2 and 3: Create a temp node and Attached temp node with head
        Node* temp = head;
    // Step 4: Update head
        head = temp->next;
    // Step 5: Isolate temp
        temp->next = NULL;
    // Step 6: Delete temp
        delete temp;
}

// 📂 2. Delete a node from the tail
void deleteFromTail(Node* head, Node* tail){
    // Step 1: Set Corner Cases: Empty LL and Single Element LL
    if(head == NULL){ 
        // Empty LL
        cout << "Can't delete, because of empty linked list" << endl;
        return;
    }
    if(head == tail){ 
        // Single Element LL
        Node* temp = head;
        delete temp;
        head->next = NULL;
        tail->next = NULL;
    }

    // Step 2: Traverse second last node (PREV)
    Node* prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }

    // Step 3: Isolate PREV
    prev->next = NULL;

    // Step 4: Delete tail
    delete tail;

    // Step 5: Update tail
    tail = prev;    
}

// 📂 3. Delete a node from any position
void deleteFromPosition(Node* &head, Node* &tail, int position){
    // Step 1: Set Corner Cases: Empty LL and Single Element LL
    if(head == NULL){ 
        // Empty LL
        cout << "Can't delete, because of empty linked list" << endl;
        return;
    }
    if(head == tail){ 
        // Single Element LL
        Node* temp = head;
        delete temp;
        head->next = NULL;
        tail->next = NULL;
    }

    // Delete node from head
    if(position == 1){
        deletefromHead(head, tail);
    }
    // Delete node from tail
    else if (position == getLength(head))
    {
        deleteFromTail(head, tail);
    }
    // Step 2: Build the logic to delete from middle
    else{
        // Step A: Set PREV and CURR
        Node* prev = NULL;
        Node* curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        
	    // Step B: PREV->next = CURR->next
        prev->next = curr->next;

	    // Step C: CURR->next = NULL
        curr->next = NULL;

        // Step D: Delete CURR
        delete curr;
    }  
}

// 📂 Problem 3: Remove loop (GFG)
void removeLoop(Node *head) {
    // Step 1: Find loop
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // Agar loop present hai to while ko break krdo
        if(slow == fast){
            break;
        }
    }

    // Agar loop present nhi hai
    if(fast == NULL){
        return;
    }

    // Step 2: Find starting point of loop
    slow = head;

    // Slow and fast -> 1 step
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }

    // Save strating point
    Node* startPoint = slow;
    
    // Step 3: Remove loop
    Node* temp = fast;
    while(temp->next != startPoint){
    temp = temp->next;
    }

    // last node ke next ko null krdo
    temp->next = NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    printLL(head);
    tail->next = head->next->next->next;
    removeLoop(head); // Loop mene revome kar diya hai
    printLL(head);
    return 0;
}
