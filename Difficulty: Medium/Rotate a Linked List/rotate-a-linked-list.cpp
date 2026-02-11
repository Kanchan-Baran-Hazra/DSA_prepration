/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        Node* first=head;
        Node* last=head;
        int count=0;
        
        while(last->next!=NULL){
            last=last->next;
            count++;
        }
        count++;
        k=k%count;
        
        while(k!=0){
            k--;
            head=head->next;
            first->next=NULL;
            last->next=first;
            last=last->next;
            first=head;
        }
        
        return head;
    }
};