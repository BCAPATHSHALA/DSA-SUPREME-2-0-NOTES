// 📂 Create a tail
void createTail(Node* &head, Node* &tail)
{
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Jab ye loop end ho gya hoga
    // then aapka temp wala pointer
    // last wala node par hoga
    tail = temp;
}