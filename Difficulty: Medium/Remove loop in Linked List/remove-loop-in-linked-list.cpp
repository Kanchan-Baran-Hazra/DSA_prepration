/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        if(head==NULL) return;
        Node* first=head;
        Node* slow=head;
        
        while(true){
            if(slow->next==NULL || first->next==NULL || first->next->next==NULL) return;
            slow=slow->next;
            first=first->next->next;
            if(slow==first){
                slow=head;
                while(slow!=first){
                    slow=slow->next;
                    first=first->next;
                }
                while(first->next!=slow){
                    first=first->next;
                }
                first->next=NULL;
                return;
            }
        }
    }
};