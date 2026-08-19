class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%3!=0) return false;
        int find=sum/3;
        int count=0;

        int i=0;
        int sub_sum=0;

        while(i<n){
            sub_sum+=arr[i];
            if(sub_sum==find){
                sub_sum=0;
                count++;
            }
            i++;
        }

        return count>=3;
    }
};