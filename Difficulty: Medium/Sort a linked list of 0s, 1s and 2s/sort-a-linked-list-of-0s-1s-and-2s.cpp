/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* dumZero=new Node(-1);
        Node* dumOnce=new Node(-1);
        Node* dumTwos=new Node(-1);
        
        Node* zero=dumZero;
        Node* one=dumOnce;
        Node* twos=dumTwos;
        
        Node* temp=head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }else{
                twos->next=temp;
                twos=twos->next;
            }
            temp=temp->next;
        }
        
        zero->next=(dumOnce->next==NULL)?dumTwos->next:dumOnce->next;
        one->next=dumTwos->next;
        twos->next=NULL;
        
        return dumZero->next;
    }
};