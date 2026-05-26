class Solution {
public:
    static void helper(int n,vector<string> &ans,int i,int j,string &sub){
        if(sub.size()==2*n){
            ans.push_back(sub);
            return;
        }
        if(i<n){
            sub.push_back('(');
            helper(n,ans,i+1,j,sub);
            sub.pop_back();
        }
        if(i>j){
            sub.push_back(')');
            helper(n,ans,i,j+1,sub);
            sub.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string sub="";
        helper(n,ans,0,0,sub);
        return ans;
    }
};