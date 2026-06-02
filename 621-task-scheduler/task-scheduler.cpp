class Solution {
public:
    int leastInterval(vector<char>& tasks, int K) {
        priority_queue<pair<int,int>> pq;
        queue<pair<int,int>>q;
        unordered_map<char,int>mp;
        
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        for(auto x:mp){
            pq.push({x.second,1});
        }
        
        int times=0;
        while(pq.size()!=0 || q.size()!=0){
            times+=1;
            
            while(q.size()!=0 && q.front().second==times){
                pq.push(q.front());
                q.pop();
            }
            
            if(pq.size()!=0 && pq.top().second<=times){
                pair<int,int> task=pq.top();
                pq.pop();
                
                task.first-=1;
                task.second=(times+K+1);
                
                if(task.first>0){
                    q.push({task.first,task.second});
                }
            }
        }
        
        return times;
    }
};