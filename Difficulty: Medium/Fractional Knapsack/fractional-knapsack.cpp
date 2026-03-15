class Solution {
  public:
    static bool emp(pair<int,int>a,pair<int,int>b){
        return (double)a.first/a.second>(double)b.first/b.second;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>temp;
        double ans=0;
        for(int i=0;i<val.size();i++){
            temp.push_back({val[i],wt[i]});
        }
        sort(temp.begin(),temp.end(),emp);
        
        for(int i=0;i<temp.size();i++){
            if(capacity==0) break;
            if(temp[i].second<=capacity){
                ans+=temp[i].first;
                capacity-=temp[i].second;
            }else{
                ans += (double)temp[i].first * capacity / temp[i].second;
                break;
            }
        }
        return ans;
    }
};
