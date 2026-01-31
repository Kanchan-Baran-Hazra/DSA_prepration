class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int count=0;
        int num=0;
        for(int i=0;i<arr.size();i++){
            if(count==0){
                num=arr[i];
                count+=1;
            }else if(num==arr[i])
            count+=1;
            else
            count-=1;
        }
        count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==num){
                count++;
            }
        }
        if(count>(arr.size()/2))
        return num;
        return -1;
    }
};