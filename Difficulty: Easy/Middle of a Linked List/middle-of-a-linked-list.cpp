/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        Node* slow=head;
        Node* first=head;
        while(first!=NULL && first->next!=NULL){
            slow=slow->next;
            first=first->next->next;
        }
        return slow->data;
    }
};