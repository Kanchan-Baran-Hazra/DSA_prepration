class Solution {
public:
    static void helper(int n,int k,vector<int>& temp,vector<vector<int>>& ans,int i){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<=n;j++){
            temp.push_back(j);
            helper(n,k,temp,ans,j+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(n,k,temp,ans,1);

        return ans;
    }
};