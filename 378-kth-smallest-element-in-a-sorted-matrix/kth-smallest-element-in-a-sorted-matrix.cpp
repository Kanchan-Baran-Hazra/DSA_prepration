class Solution {
public:
    static int getCount(vector<vector<int>>& matrix, int mid){
        int count=0;
        for(int i=0;i<matrix.size();i++){
            count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i=matrix[0][0];
        int n=matrix.size();
        int m=matrix[0].size();
        int j=matrix[n-1][m-1];

        while(i<j){
            int mid=i+(j-i)/2;
            int count=getCount(matrix,mid);

            if(count<k) i=mid+1;
            else j=mid;
        }
        return i;
    }
};