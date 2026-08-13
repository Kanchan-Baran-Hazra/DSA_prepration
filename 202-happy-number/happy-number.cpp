class Solution {
public:
    static int getsum(int n){
        int sum=0;
        while(n!=0){
            int num=n%10;
            sum+=(num*num);
            n/=10;
        }
        return sum;
    }
    static bool helper(int n,unordered_map<int ,int> &mp){
        if(n==1) return true;
        int sum=getsum(n);
        if(mp.find(sum)!=mp.end()) return false;
        mp[sum]++;
        return helper(sum,mp);
    }
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        return helper(n,mp);
    }
};