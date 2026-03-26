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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        n--;
        while(n>0){
            fast=fast->next;
            n--;
        }
        while(fast->next!=NULL){
            prev=temp;
            temp=temp->next;
            fast=fast->next;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next=temp->next;
        if(temp->next!=NULL)
        temp->next=NULL;

        return head;
    }
};