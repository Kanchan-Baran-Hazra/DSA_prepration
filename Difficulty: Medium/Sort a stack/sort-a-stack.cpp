class Solution {
  public:
    void helper(stack<int> &st,int temp){
        if(st.size()==0 || st.top()<=temp){
            st.push(temp);
            return;
        }
        int top=st.top();
        st.pop();
        helper(st,temp);
        st.push(top);
        
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.size()==0) return;
        int top=st.top();
        st.pop();
        sortStack(st);
        helper(st,top);
    }
};
