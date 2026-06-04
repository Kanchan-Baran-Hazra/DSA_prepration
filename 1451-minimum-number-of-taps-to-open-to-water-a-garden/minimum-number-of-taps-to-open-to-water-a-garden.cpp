class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // vector<pair<int,int>>vec;
        vector<int>temp(n+1,0);
        // int n=ranges.size();
        for(int i=0;i<=n;i++){
            int x=max(0,i-ranges[i]);
            int y=min(n,i+ranges[i]);
            // vec.push_back({x,y});
            temp[x]=max(temp[x],y);
        }

        int tap_n=0;
        int max_idx=0;
        int cur_pos=0;

        for(int i=0;i<n;i++){
            max_idx=max(max_idx,temp[i]);
            if(i>=max_idx) return -1;
            if(i==cur_pos){
                tap_n++;
                cur_pos=max_idx;
            }
        }
        return tap_n;
    }
};