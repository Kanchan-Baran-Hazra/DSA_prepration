class Solution {
  public:
    void helper(stack<int> &st){
        if(st.size()==0) return;
        int temp=st.top();
        st.pop();
        helper(st);
        stack<int>st1;
        while(st.size()!=0){
            st1.push(st.top());
            st.pop();
        }
        st.push(temp);
        while(st1.size()!=0){
            st.push(st1.top());
            st1.pop();
        }
    }
    void reverseStack(stack<int> &st) {
        // code here
        helper(st);
        return;
    }
};