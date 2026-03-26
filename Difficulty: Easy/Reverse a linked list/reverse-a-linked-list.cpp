/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node* left=NULL;
        Node* pres=head;
        Node* next=pres->next;
        
        while(next!=NULL){
            pres->next=left;
            left=pres;
            pres=next;
            next=next->next;
        }
        pres->next=left;
        left=pres;
        return pres;
    }
};