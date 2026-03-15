class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;

        for(int i=temperatures.size()-1;i>=0;i--){
            while(pq.size()!=0 && pq.top().first<=temperatures[i]){
                pq.pop();
            }
            if(pq.size()==0){
                ans.push_back(0);
            }else{
                ans.push_back(pq.top().second-i);
            }
            pq.push({temperatures[i],i});
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};