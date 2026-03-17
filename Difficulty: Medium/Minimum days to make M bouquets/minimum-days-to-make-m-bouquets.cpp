class Solution {
public:
    bool isPoss(vector<int>& arr, int k, int m, int mid){
        int bouquets = 0, flowers = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= mid){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        if(arr.size() < k * m) return -1;

        int l = *min_element(arr.begin(), arr.end());
        int r = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(isPoss(arr, k, m, mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};