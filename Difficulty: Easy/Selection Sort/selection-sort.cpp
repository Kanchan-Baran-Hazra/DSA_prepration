class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            int val=INT_MAX;
            int index=-1;
            for(int j=i;j<arr.size();j++){
                if(val>arr[j]){
                    val=arr[j];
                    index=j;
                }
            }
            swap(arr[i],arr[index]);
            
        }
        return;
    }
};