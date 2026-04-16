class Solution {
public:
    int hammingWeight(int n) {
        int num=0;
        int count=0;
        while(n>0){
            num=n & (-n);
            count++;
            n-=num;
        }

        return count;
    }
};