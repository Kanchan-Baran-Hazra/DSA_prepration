class Solution {
public:
    static bool emp(pair<char,int>a, pair<char,int>b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }

    string frequencySort(string &s) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> temp;
        string ans = "";

        for(char c : s){
            mp[c]++;
        }

        for(auto x : mp){
            temp.push_back(x);
        }

        sort(temp.begin(), temp.end(), emp);

        for(auto &p : temp){
            ans.append(p.second, p.first); // 🔥 best way
        }

        return ans;
    }
};