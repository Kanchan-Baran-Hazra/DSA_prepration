class Solution {
public:
    static bool enm(vector<int>&a,vector<int>&b){
        // if(a[2]!=b[2])
        return a[1]<b[1];
        // else return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),enm);
        int count=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<trips.size();i++){
            if(count+trips[i][0]<=capacity){
                pq.push({trips[i][2],trips[i][0]});
                count+=trips[i][0];
            }else{
                while(pq.size()!=0 && pq.top().first<=trips[i][1]){
                    pair<int,int>temp=pq.top();
                    pq.pop();
                    count-=temp.second;
                }
                if(count+trips[i][0]<=capacity){
                    pq.push({trips[i][2],trips[i][0]});
                    count+=trips[i][0];
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};