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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode* rev_head=reverse(head);
        ListNode* temp=rev_head->next;
        ListNode* last_ptr=rev_head;
        priority_queue<int>pq;
        pq.push(last_ptr->val);
        while(temp!=NULL){
            if(pq.top()<=temp->val){
                last_ptr->next=temp;
                pq.push(temp->val);
                last_ptr=last_ptr->next;
            }
            temp=temp->next;
        }
        last_ptr->next = NULL;
        ListNode* rev_head1=reverse(rev_head);
        return rev_head1;
    }
};