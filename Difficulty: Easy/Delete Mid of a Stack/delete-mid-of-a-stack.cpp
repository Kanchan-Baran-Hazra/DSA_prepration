class Solution {
  public:
    // Function to delete middle element of a stack.
    void helper(stack<int> &st,int pos){
        if(st.size()==pos){
            st.pop();
            return;
        }
        int current=st.top();
        st.pop();
        helper(st,pos);
        st.push(current);
    }
    void deleteMid(stack<int>& st) {
        // code here..
        int pos=ceil(st.size()/2.0);
        helper(st,pos);
    }
};