class Solution {
  public:
    void helper(string s,int k,set<string> &st){
        if(s.size()<=k) return;
        for(int i=k;i<s.size();i++){
            swap(s[i],s[k]);
            st.insert(s);
            helper(s,k+1,st);
            swap(s[i],s[k]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>st;
        vector<string>ans;
        helper(s,0,st);
        for(auto x:st){
            ans.push_back(x);
        }
        
        return ans;
    }
};
