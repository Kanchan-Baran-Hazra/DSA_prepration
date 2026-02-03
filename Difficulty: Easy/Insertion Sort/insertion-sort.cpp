class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            int val=arr[i];
            int j=i-1;
            while(j>=0 && val<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=val;
        }
        return;
    }
};