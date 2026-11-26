class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }

        if(total%2) return false;

        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            if(sum==total/2) return true;
        }

        sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=grid[j][i];
            }
            if(sum==total/2) return true;
        }

        return false;
    }
};