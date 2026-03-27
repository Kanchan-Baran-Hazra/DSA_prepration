/*
class Node {
  public:
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
    Node *pairwiseSwap(Node *head) {
        // code here
        Node* corr=head;
        Node* next=head->next;
        if(next==NULL) return head;
        
        while(next!=NULL){
            swap(corr->data,next->data);
            corr=next->next;
            if(corr!=NULL)
            next=corr->next;
            else next=next->next;
        }
        
        return head;
    }
};