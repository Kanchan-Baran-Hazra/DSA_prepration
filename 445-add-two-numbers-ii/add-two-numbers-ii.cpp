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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1;
        stack<int>st2;
        stack<int>ans;

        ListNode* h1=l1;
        ListNode* h2=l2;

        while(h1!=NULL){
            st1.push(h1->val);
            h1=h1->next;
        }

        while(h2!=NULL){
            st2.push(h2->val);
            h2=h2->next;
        }

        ListNode* dumnode=new ListNode(-1);
        ListNode* ptr=dumnode;
        int sum=0;
        int carry=0;

        while(st1.size()!=0 || st2.size()!=0){
            sum+=carry;

            if(st1.size()!=NULL){
                sum+=st1.top();
                st1.pop();
            }

            if(st2.size()!=NULL){
                sum+=st2.top();
                st2.pop();
            }

            ans.push(sum%10);
            carry=sum/10;
            sum=0;
        }
        if(carry!=0) ans.push(1);
        while(ans.size()!=0){
            ListNode* temp=new ListNode(ans.top());
            ans.pop();
            ptr->next=temp;
            ptr=temp;
        }
        
        return dumnode->next;
    }
};