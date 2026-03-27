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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>>st;
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        vector<int>ans(count-1,0);
        temp=head;
        count=0;
        while(temp!=NULL){
            if(st.size()==0 || temp->val<st.top().first){
                st.push({temp->val,count});
            }else{
                while(st.size()!=0 && st.top().first<temp->val){
                    pair<int,int> top=st.top();
                    st.pop();
                    ans[top.second]=temp->val;
                }
                st.push({temp->val,count});
            }
            temp=temp->next;
            count++;
        }

        return ans;
    }
};