class Solution {
  public:
    void insertStack(stack<int> &st,int top){
        if(st.size()==0){
            st.push(top);
            return;
        }
        int current=st.top();
        st.pop();
        insertStack(st,top);
        st.push(current);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size()==0) return;
        int top=st.top();
        st.pop();
        reverseStack(st);
        insertStack(st,top);
    }
};