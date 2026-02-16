class Solution {
public:
    int trap(vector<int>& height) {
        int max_idx=-1;
        vector<int>leftmax;
        vector<int>rightmax;
        int ans=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>=max_idx){
                leftmax.push_back(-1);
                max_idx=height[i];
            }else{
                leftmax.push_back(max_idx);
            }
        }

        max_idx=-1;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>=max_idx){
                rightmax.push_back(-1);
                max_idx=height[i];
            }else{
                rightmax.push_back(max_idx);
            }
        }
        reverse(rightmax.begin(),rightmax.end());

        for(int i=0;i<leftmax.size();i++){
            if(leftmax[i]==-1 || rightmax[i]==-1) continue;
            else{
                ans+=min(leftmax[i],rightmax[i])-height[i];
            }
        }
        return ans;
    }
};