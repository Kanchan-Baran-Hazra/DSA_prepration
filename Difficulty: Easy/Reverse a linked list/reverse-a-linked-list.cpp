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
        Node* prev=NULL;
        Node* mid;
        Node* first;
        mid=head;
        first=head->next;
        while(first!=NULL){
            mid->next=prev;
            prev=mid;
            mid=first;
            first=first->next;
        }
        mid->next=prev;
        return mid;
    }
};