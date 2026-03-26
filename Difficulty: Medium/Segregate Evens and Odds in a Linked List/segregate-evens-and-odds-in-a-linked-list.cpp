// User function template for C++

/*
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
    Node* divide(Node* head) {
        // code here
        Node* odd=NULL;
        Node* even=NULL;
        Node* temp=head;
        Node* oddHead=NULL;
        Node* evenHead=NULL;
        
        while(temp!=NULL){
            Node* tempNext=temp->next;
            if(temp->data%2==0){
                if(even==NULL){
                    even=temp;
                    evenHead=even;
                }else{
                    even->next=temp;
                    even=even->next;
                }
            }else{
                if(odd==NULL){
                    odd=temp;
                    oddHead=odd;
                }else{
                    odd->next=temp;
                    odd=odd->next;
                }
            }
            temp->next=NULL;
            temp=tempNext;
        }
        
        if(evenHead!=NULL){
            even->next=oddHead;
            return evenHead;
        }
        
        return oddHead;
    }
};