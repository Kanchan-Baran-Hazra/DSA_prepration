class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;

        while(i < j){
            int mid = i + (j - i) / 2;

            if(arr[mid] > arr[j])
                i = mid + 1;   // min in right half
            else
                j = mid;       // min in left half (including mid)
        }
        return i; // index of minimum = rotations
    }
};
