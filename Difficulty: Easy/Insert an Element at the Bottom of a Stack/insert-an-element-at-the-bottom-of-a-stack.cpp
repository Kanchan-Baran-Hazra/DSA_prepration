// User function Template for C++

class Solution {
  public:
    void helper(stack<int> &st,int x){
        if(st.size()==0){
            st.push(x);
            return;
        }
        int current=st.top();
        st.pop();
        helper(st,x);
        st.push(current);
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        helper(st,x);
        return st;
    }
};