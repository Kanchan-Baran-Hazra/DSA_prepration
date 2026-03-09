class Solution {
  public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        if(start.size()==0) return 0;
        vector<vector<int>>temp;
        for (int i = 0; i < start.size(); i++)
        {
            vector<int>vec;
            vec.push_back(start[i]);
            vec.push_back(end[i]);
            temp.push_back(vec);
        }
        sort(temp.begin(), temp.end(),cmp);
        
        int maxi=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<temp.size();i++){
            if(pq.size()!=0 && pq.top()<=temp[i][0]){
                pq.pop();
            }
            maxi=max((int)pq.size()+1,maxi);
            pq.push(temp[i][1]);
        }
        return maxi;
    }
};
