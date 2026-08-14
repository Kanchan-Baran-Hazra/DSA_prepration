class Solution {
public:
    static void push_val(string &s,int count){
        string s1=to_string(count);
        for(int i=0;i<s1.size();i++){
            s.push_back(s1[i]);
        }
    }
    int compress(vector<char>& nums) {
        if(nums.size()==1) return 1;
        int count=1;
        int i=1;
        int n=nums.size();
        string ans="";
        while(i<n){
            if(nums[i]==nums[i-1]){
                count++;
            }else{
                ans.push_back(nums[i-1]);
                if(count>1) push_val(ans,count);
                count=1;
            }
            i++;
        }
        ans.push_back(nums[i-1]);
        if(count>1) push_val(ans,count);

        for(int j=0;j<ans.size();j++){
            nums[j]=ans[j];
        }
        return ans.size();
    }
};