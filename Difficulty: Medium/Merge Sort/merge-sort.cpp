class Solution {
  public:
    void margeArray(vector<int>& arr, int l, int r,int mid){
        vector<int>temp;
        int i=l;
        int j=mid+1;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int k=0;k<temp.size();k++){
            arr[k+l]=temp[k];
        }
        return;
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            margeArray(arr,l,r,mid);
        }
        return;
    }
};