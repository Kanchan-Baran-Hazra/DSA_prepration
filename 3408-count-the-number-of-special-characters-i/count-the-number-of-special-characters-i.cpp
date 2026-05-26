class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        int count=0;

        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }

        for(auto x:mp){
            if(x.first>96){
                if(mp.find(x.first-32)!=mp.end()) count++;
            }else{
                if(mp.find(x.first+32)!=mp.end()) count++;
            }
        }

        return count/2;
    }
};