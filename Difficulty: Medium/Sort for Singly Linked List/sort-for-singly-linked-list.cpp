/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* margeSort(Node* left,Node* right){
        if(left==NULL || right==NULL){
            return (left==NULL)?right:left;
        }
        
        if(left->data<=right->data){
            left->next=margeSort(left->next,right);
            return left;
        }else{
            right->next=margeSort(left,right->next);
            return right;
        }
    }
    Node* insertionSort(struct Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* first=head;
        Node* slow=head;
        Node* prev=slow;
        
        while(first!=NULL && first->next!=NULL){
            first=first->next->next;
            prev=slow;
            slow=slow->next;
        }
        
        prev->next=NULL;
        Node* left=insertionSort(head);
        Node* right=insertionSort(slow);
        
        return margeSort(left,right);
    }
};