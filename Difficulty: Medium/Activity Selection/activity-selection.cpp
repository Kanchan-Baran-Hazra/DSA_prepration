class Solution {
  public:
    static bool emp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>>temp;
        for(int i=0;i<start.size();i++){
            vector<int>vec;
            vec.push_back(start[i]);
            vec.push_back(finish[i]);
            temp.push_back(vec);
        }
        sort(temp.begin(),temp.end(),emp);
        
        int count=1;
        int pos=0;
        for(int i=1;i<temp.size();i++){
            if(temp[pos][1]<temp[i][0]){
                count++;
                pos=i;
            }
        }
        
        return count;
    }
};