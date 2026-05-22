class Solution {
	public:
	void quickSort(vector<int>& arr, int low, int high) {
		// code here
		if (low<high) {
			int idx = partition(arr, low, high);
			quickSort(arr, low, idx - 1);
			quickSort(arr, idx + 1, high);
		}
	}
	
	public:
	int partition(vector<int>& arr, int low, int high) {
		
		// code here
		int i = low - 1;
		int prev = high;
		int j = low;
		
		while (j <= high) {
			if (arr[j]<arr[prev]) {
				i++;
				swap(arr[i], arr[j]);
			}
			j++;
		}
		
		i++;
		swap(arr[i], arr[prev]);
		
		return i;
	}
};
