class Solution {
public:
    static bool cmp(int &i,int &j){
        return i>j;
    }
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),cmp);
        int ans=0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3==0) continue;
            ans+=cost[i];
            // cout<<cost[i]<<endl;
        }

        return ans;
    }
};