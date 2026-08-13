/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mp;
        while(headA!=NULL || headB!=NULL){
            if(headA==headB) return headA;
            if(mp.find(headA)!=mp.end()) return headA;
            if(mp.find(headB)!=mp.end()) return headB;


            if(headA!=NULL){
                mp[headA]++;
                headA=headA->next;
            }
            if(headB!=NULL){
                mp[headB]++;
                headB=headB->next;
            }
        }
        return NULL;
    }
};