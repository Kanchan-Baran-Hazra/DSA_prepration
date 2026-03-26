/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        // code here
        Node* new_node=new Node(val);
        if(pos==1){
            new_node->next=head;
            head=new_node;
            return head;
        }
        Node* temp=head;
        Node* prev=NULL;
        pos--;
        while(pos>0){
            pos--;
            prev=temp;
            temp=temp->next;
        }
        prev->next=new_node;
        new_node->next=temp;
        
        return head;
    }
};