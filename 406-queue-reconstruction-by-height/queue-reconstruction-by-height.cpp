class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] > b[0]; // Primary sort: Ascending by Roll Number
        }
        return a[1] < b[1]; // Secondary sort: Alphabetical by Name
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        int n=people.size();

        vector<vector<int>>ans;
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin()+people[i][1],people[i]);
        }

        return ans;
    }
};