class Solution {
public:
    double reqHours(vector<int>& dist,int maxi){
        double count=0;double sum=0;
        for(int i=0;i<dist.size()-1;i++){
            count+=ceil((double)dist[i]/maxi);
        }
        count+=(double)dist[dist.size()-1]/maxi;
        return count;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int r=1e7;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            double hours=reqHours(dist,mid);
            if(hours<=hour){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }

        return ans;
    }
};