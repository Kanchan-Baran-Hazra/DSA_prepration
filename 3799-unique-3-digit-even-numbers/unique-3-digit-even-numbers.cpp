#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();

        // i -> Hundreds place, j -> Tens place, k -> Units place
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue; // Leading zeros not allowed

            for (int j = 0; j < n; ++j) {
                if (i == j) continue; // Cannot reuse the same index

                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue; // Cannot reuse indices
                    
                    // Units place must be even
                    if (digits[k] % 2 == 0) {
                        int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                        uniqueNumbers.insert(number);
                    }
                }
            }
        }

        return uniqueNumbers.size();
    }
};