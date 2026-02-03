class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            bool isSwap=false;
            for(int j=0;j<arr.size()-1-i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    isSwap=true;
                }
            }
            if(!isSwap) return;
        }
        return;
    }
};