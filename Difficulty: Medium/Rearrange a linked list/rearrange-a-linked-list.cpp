/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        Node* odd=head;
        Node* even=head->next;
        Node* even_start=head->next;
        
        while(odd->next!=NULL && odd->next->next!=NULL ||even!=NULL && even->next!=NULL){
            if(odd->next!=NULL && odd->next->next!=NULL){
                odd->next=odd->next->next;
                odd=odd->next;
            }
            if(even->next!=NULL){
                even->next=even->next->next;
                even=even->next;
            }
        }
        
        odd->next=even_start;
    }
};