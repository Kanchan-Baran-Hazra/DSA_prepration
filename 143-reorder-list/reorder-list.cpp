class Solution {
public:

    ListNode* find_mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

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

    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // find middle
        ListNode* mid = find_mid(head);

        // reverse second half
        ListNode* second = reverse(mid->next);

        mid->next = NULL;

        // merge
        ListNode* first = head;

        while(second != NULL){

            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};