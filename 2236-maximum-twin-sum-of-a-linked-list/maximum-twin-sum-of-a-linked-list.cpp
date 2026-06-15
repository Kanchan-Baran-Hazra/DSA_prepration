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
    static ListNode* getMid(ListNode* head){
        ListNode* temp=head;
        ListNode* temp1=head;
        ListNode* prev=NULL;

        while(temp1!=NULL && temp1->next!=NULL){
            prev=temp;
            temp=temp->next;
            temp1=temp1->next->next;
        }

        return prev;
    }
    static ListNode* revList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head->next;

        while(temp!=NULL){
            head->next=prev;
            prev=head;
            head=temp;
            temp=temp->next;
        }
        head->next=prev;

        return head;
    }
    int pairSum(ListNode* head) {
        ListNode* mid_prev=getMid(head);
        ListNode* mid=mid_prev->next;
        mid_prev->next=NULL;
        ListNode* temp=revList(mid);
        mid_prev->next=temp;

        ListNode* s1=head;
        ListNode* s2=temp;
        int maxi=INT_MIN;
        while(s2!=NULL){
            int sum=s1->val+s2->val;
            maxi=max(maxi,sum);
            s1=s1->next;
            s2=s2->next;
        }

        return maxi;
    }
};