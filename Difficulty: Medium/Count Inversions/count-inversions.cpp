class Solution {
  public:
    int mearGe(vector<int> &arr,int i,int j,int mid){
        int l=i;
        int r=mid+1;
        int ans=0;
        vector<int>temp;
        while(l<=mid && r<=j){
            if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;
            }else{
                temp.push_back(arr[r]);
                r++;
                ans=ans+(mid-l+1);
            }
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(r<=j){
            temp.push_back(arr[r]);
            r++;
        }
        for(int k=0;k<temp.size();k++){
            arr[k+i]=temp[k];
        }
        return ans;
    }
    
    int margeSort(vector<int> &arr,int i,int j){
        if(i<j){
            int mid=i+(j-i)/2;
            int left=margeSort(arr,i,mid);
            int right=margeSort(arr,mid+1,j);
            
            return left+right+mearGe(arr,i,j,mid);
        }
        return 0;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return margeSort(arr,0,arr.size()-1);
    }
};