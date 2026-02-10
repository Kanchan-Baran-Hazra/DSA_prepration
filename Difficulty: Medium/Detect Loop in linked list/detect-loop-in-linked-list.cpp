/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        Node* first=head;
        Node* slow=head;
        
        while(true){
            if(slow->next==NULL || first->next==NULL || first->next->next==NULL) break;
            slow=slow->next;
            first=first->next->next;
            
            if(slow==first) return true;
        }
        return false;
    }
};