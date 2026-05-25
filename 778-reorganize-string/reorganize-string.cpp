class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto x:mp){
            if(x.second>(s.size()+1)/2) return "";
            pq.push({x.second,x.first});
        }

        string ans="";
        while(pq.size()>1){
            pair<int,char> num1=pq.top();
            pq.pop();
            pair<int,char> num2=pq.top();
            pq.pop();

            ans.push_back(num1.second);
            num1.first--;
            ans.push_back(num2.second);
            num2.first--;

            if(num1.first>0) pq.push(num1);
            if(num2.first>0) pq.push(num2);
        }

        if(pq.size()!=0){
            pair<int,char> num1=pq.top();
            pq.pop();

            if(num1.first>1) return "";
            ans.push_back(num1.second);
        }

        return ans;
    }
};