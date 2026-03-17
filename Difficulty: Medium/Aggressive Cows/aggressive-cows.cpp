class Solution {
  public:
    bool isPoss(vector<int> &stalls, int k,int mini){
        int prev=stalls[0];
        k--;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i] - prev >= mini){
                k--;
                if(k==0) return true;
                prev=stalls[i];
            }
        }
        return (k==0)? true:false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int ans=0;
        sort(stalls.begin(), stalls.end());
        int l=1;
        int r=stalls[stalls.size()-1]-stalls[0];
            
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(isPoss(stalls,k,mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        
        return ans;
    }
};