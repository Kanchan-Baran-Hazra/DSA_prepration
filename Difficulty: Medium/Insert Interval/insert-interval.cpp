class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int first=intervals[0][0];
        int second=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>second){
                vector<int>temp;
                temp.push_back(first);
                temp.push_back(second);
                ans.push_back(temp);
                first=intervals[i][0];
                second=intervals[i][1];
            }else{
                if(intervals[i][0]<first)
                first=intervals[i][0];
                if(intervals[i][1]>second)
                second=intervals[i][1];
            }
        }
        vector<int>temp;
        temp.push_back(first);
        temp.push_back(second);
        ans.push_back(temp);
        return ans;
    }
};