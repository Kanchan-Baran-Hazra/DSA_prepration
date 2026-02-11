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
    int getLen(Node* ptr){
        int len=0;
        while(ptr!=NULL){
            len++;
            ptr=ptr->next;
        }
        return len;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1=getLen(head1);
        int len2=getLen(head2);
        
        while(len1>len2){
            len1--;
            head1=head1->next;
        }
        
        while(len1<len2){
            len2--;
            head2=head2->next;
        }
        
        while(head1!=head2){
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
    }
};