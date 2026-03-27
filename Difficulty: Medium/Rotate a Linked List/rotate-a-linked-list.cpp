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
        Node* curr=head;
        int count=1;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        k=k%count;
        for(int i=0;i<k;i++){
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            curr->next=temp;
            curr=curr->next;
        }
        
        return head;
    }
};