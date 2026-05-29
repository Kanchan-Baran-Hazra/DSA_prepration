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
    ListNode* sortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> mp;
        ListNode* temp=head;
        while(temp!=NULL){
            mp.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(mp.size()!=0){
            temp->val=mp.top();
            mp.pop();
            temp=temp->next;
        }

        return head;
    }
};