class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum=0;
        int carry=0;
        int i=digits.size()-1;
        while(i>=0){
            if(i==digits.size()-1) sum=digits[i]+1+carry;
            else sum=digits[i]+carry;
            if(sum<10){
                digits[i]=sum;
                carry=0;
                return digits;
            }else{
                int mod=sum%10;
                digits[i]=mod;
                sum/=10;
                carry=sum;
                sum=0;
            }
            i--;
        }
        if(carry!=0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};