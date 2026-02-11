/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* ptr=head;
        Node* ptr1=head;
        while(ptr!=NULL && k>0){
            ptr=ptr->next;
            k--;
        }
        if(ptr==NULL && k!=0) return -1;
        else if(ptr==NULL && k==0) return head->data;
        
        while(ptr!=NULL){
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        return ptr1->data;
    }
};