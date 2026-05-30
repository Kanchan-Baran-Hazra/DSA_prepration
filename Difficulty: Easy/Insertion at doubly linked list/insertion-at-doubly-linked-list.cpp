/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
    Node* temp = head;

    for(int i = 0; i < p; i++) {
        temp = temp->next;
    }

    Node* new_node = new Node(x);

    new_node->next = temp->next;
    new_node->prev = temp;

    if(temp->next)
        temp->next->prev = new_node;

    temp->next = new_node;

    return head;
}
};