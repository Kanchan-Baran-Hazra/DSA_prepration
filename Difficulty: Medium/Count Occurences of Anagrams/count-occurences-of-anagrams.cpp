// User function template for C++
class Solution {
  public:
    int search(string &txt, string &arr) {
        // code here
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        for(int k=0;k<txt.size();k++){
            mp[txt[k]]++;
        }
        int count=mp.size();
        while(j<arr.size()){
            // cout<<"entered"<<j<<endl;
            if(mp.find(arr[j])!=mp.end()){
                mp[arr[j]]--;
                if(mp[arr[j]]==0) count--;
            }
            if(j-i+1<txt.size()){
                j++;
            }else{
                // cout<<"entered"<<endl;
                if(count==0) ans++;
                if(mp.find(arr[i])!=mp.end()){
                    if(mp[arr[i]]==0) count++;
                    mp[arr[i]]++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};