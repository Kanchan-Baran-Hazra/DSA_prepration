class Solution {
    void dfs(vector<vector<int>>& stones,vector<bool>& mark,int pos){
        mark[pos]=true;
        int x=stones[pos][0];
        int y=stones[pos][1];

        for(int i=0;i<stones.size();i++){
            if(!mark[i] && (stones[i][0]==x || stones[i][1]==y)){
                dfs(stones,mark,i);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> mark(n,false);

        int group=0;
        for(int i=0;i<n;i++){
            if(!mark[i]){
                dfs(stones,mark,i);
                group++;
            }
        }
        return n-group;
    }
};