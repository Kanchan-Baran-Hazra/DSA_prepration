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
};