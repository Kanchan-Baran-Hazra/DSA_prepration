/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *first=head;
        Node *slow=head;
        
        while(first!=NULL && first->next!=NULL){
            first=first->next->next;
            slow=slow->next;
            
            if(first==slow){
                int count=1;
                while(first->next!=slow){
                    first=first->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
    }
};