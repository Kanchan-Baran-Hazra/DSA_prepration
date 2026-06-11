class Solution {
public:
    static int canForm(string s,unordered_map<char,int>mp){
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
            }
            else return false;
        }

        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(canForm(words[i],mp)) ans+=words[i].size();
        }

        return ans;
    }
};