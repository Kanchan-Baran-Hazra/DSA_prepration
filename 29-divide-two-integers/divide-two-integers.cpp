class Solution {
public:
    int divide(int dvd, int dvr) {
        if (dvd == INT_MIN && dvr == -1)
            return INT_MAX;
        long long dividend = llabs((long long)dvd);
        long long divisor = llabs((long long)dvr);
        long long ans=0;
        while(dividend>=divisor){
            int count=0;
            while(dividend>=(divisor<<(count+1))){
                count++;
            }

            dividend-=(divisor<<count);
            ans+=(1<<count);
        }

        if((dvd<0) ^ (dvr<0)) ans=-ans;

        return ans;
    }
};