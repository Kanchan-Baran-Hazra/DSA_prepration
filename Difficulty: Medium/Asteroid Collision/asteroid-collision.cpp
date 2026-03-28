class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        stack<int> st;
        for(int i=0;i<a.size();i++) {
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && a[i]<0) {
                if(abs(a[i])>abs(st.top())) 
                    st.pop();
                else if(abs(a[i])==abs(st.top())) {
                    st.pop();
                    destroyed=true;
                    break;
                }
                else {
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed)
                st.push(a[i]);
        }
        
        vector<int> ans;
        while(!st.empty()) {
            int e=st.top();
            ans.push_back(e);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};