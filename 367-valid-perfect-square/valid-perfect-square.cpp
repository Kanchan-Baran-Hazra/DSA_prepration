class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0;
        int j=num;
        while(i<=j){
            int mid=i+(j-i)/2;
            if((long long)mid*mid==num) return true;
            else if((long long)mid*mid>num) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};