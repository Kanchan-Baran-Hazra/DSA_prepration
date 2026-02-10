/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        Node* ptr=new Node();
        Node* prv=new Node();
        ptr=head;
        
        for(int i=1;i<x;i++){
            prv=ptr;
            ptr=ptr->next;
        }
        
        if(ptr==head){
            head=head->next;
            return head;
        }else{
            prv->next=ptr->next;
            return head;
        }
        return head;
    }
};