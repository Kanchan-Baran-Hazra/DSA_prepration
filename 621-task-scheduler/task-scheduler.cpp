class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int ans=0;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }

        for(auto x:mp){
            pq.push(x.second);
        }

        while(pq.size()!=0){
            int count=0;
            vector<int>temp;
            while(pq.size()!=0 && count<n+1){
                temp.push_back(pq.top());
                pq.pop();
                count++;
            }

            int sig=false;
            for(int i=0;i<temp.size();i++){
                temp[i]--;
                if(temp[i]>0){
                    pq.push(temp[i]);
                    sig=true;
                }
            }
            if(sig){
                ans+=(n+1);
            }else{
                ans+=temp.size();
            }
        }

        return ans;
    }
};