class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return stones[0];
        priority_queue<int>mh;

        for(int i=0;i<stones.size();i++){
            mh.push(stones[i]);
        }

        while(mh.size()>1){
            int num1=mh.top();
            mh.pop();
            int num2=mh.top();
            mh.pop();

            int diff=num1-num2;
            diff=(diff<0)?-diff:diff;
            if(diff==0) continue;
            mh.push(diff);
        }
        return mh.size()>0?mh.top():0;
    }
};