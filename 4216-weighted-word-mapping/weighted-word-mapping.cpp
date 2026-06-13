class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            int sum = 1;

            for (int j = 0; j < words[i].size(); j++) {
                sum += weights[words[i][j] - 'a'];
            }

            sum = (26 - (sum % 26)) % 26;
            ans.push_back('a' + sum);
        }

        return ans;
    }
};