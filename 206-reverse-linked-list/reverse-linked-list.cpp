class Solution {
public:
    static void helper(ListNode*& i, ListNode*& j, ListNode*& k) {
        if (k == NULL) {
            j->next = i;
            return;
        }

        j->next = i;
        i = j;
        j = k;
        k = k->next;

        helper(i, j, k);
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* i = NULL;
        ListNode* j = head;
        ListNode* k = head->next;

        helper(i, j, k);

        return j;
    }
};