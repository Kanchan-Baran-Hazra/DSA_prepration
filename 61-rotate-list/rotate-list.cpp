/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* temp=head;
        int count=1;
        ListNode* tell=head;
        while(tell->next!=NULL){
            count++;
            tell=tell->next;
        }
        if(k%count==0) return head;
        else k=k%count;

        for(int i=0;i<count-k;i++){
            ListNode* current=temp;
            temp=temp->next;
            current->next=NULL;
            tell->next=current;
            tell=tell->next;
        }

        return temp;
    }
};