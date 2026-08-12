class Solution {
public:
    int secondHighest(string s) {
        priority_queue<int>pq;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int x=s[i]-'0';
                pq.push(x);
            }
        }
        if(pq.size()<2) return -1;
        int x=pq.top();
        while(pq.size()!=0 && pq.top()==x){
            pq.pop();
        }
        return (pq.size()==0)?-1:pq.top();

    }
};