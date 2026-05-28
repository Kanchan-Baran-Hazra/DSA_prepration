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
    static void helper(ListNode* dummy, ListNode* i, ListNode* j) {
        if (i == NULL) {
            dummy->next = j;
            return;
        }

        if (j == NULL) {
            dummy->next = i;
            return;
        }

        if (i->val <= j->val) {
            ListNode* nnode = new ListNode(i->val);
            dummy->next = nnode;
            helper(nnode, i->next, j);
        } else {
            ListNode* nnode = new ListNode(j->val);
            dummy->next = nnode;
            helper(nnode, i, j->next);
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();

        helper(dummy, list1, list2);

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];

        int i=0;
        int j=1;
        while(j<lists.size()){
            ListNode* head=mergeTwoLists(lists[i],lists[j]);
            lists.push_back(head);
            i+=2;
            j+=2;
        }

        return lists[i];

    }
};