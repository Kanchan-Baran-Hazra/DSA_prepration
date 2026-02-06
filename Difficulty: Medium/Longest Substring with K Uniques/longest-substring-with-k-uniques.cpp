class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int i=0;
        int j=0;
        int ans=-1;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()==k){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp.size()<k){
                j++;
            }else{
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};