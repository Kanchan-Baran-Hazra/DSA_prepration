class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int>pq;

        while(n>0){
            int num=n%10;
            pq.push(num);
            n/=10;
        }
        int num1=pq.top();
        pq.pop();
        int num2=pq.top();
        pq.pop();

        return num1*num2;
    }
};