class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        priority_queue<pair<int,char>>pq;

        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        int ans=0;
        int count=1;
        while(pq.size()!=0){
            pair<int,char>p=pq.top();
            pq.pop();
            if(count<=8){
                ans+=(p.first*1);
            }else if(count<=16){
                ans+=(p.first*2);
            }else if(count<=24){
                ans+=(p.first*3);
            }else{
                ans+=(p.first*4);
            }
            count++;
        }

        return ans;
    }
};