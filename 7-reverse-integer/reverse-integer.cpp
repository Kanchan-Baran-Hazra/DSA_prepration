class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        long long x1=x;
        if(x1<0) x1=-x1;
        while (x1 != 0) {
            int digit = x1 % 10;
            ans = ans * 10 + digit;

            if (ans > INT_MAX || ans < INT_MIN)
                return 0;

            x1 /= 10;
        }
        if(x<0) ans=-ans;

        if(ans>INT_MAX || ans<INT_MIN) return 0;

        return (int)ans;
    }
};