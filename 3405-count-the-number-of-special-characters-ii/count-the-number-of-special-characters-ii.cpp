class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>lower_mp;
        unordered_map<char,int>upper_mp;

        for(int i=0;i<word.size();i++){
            if(int(word[i])>96){
                lower_mp[word[i]]=i;
            }else{
                if(upper_mp.find(word[i])==upper_mp.end()){
                    upper_mp[word[i]]=i;
                }
            }
        }
        int count=0;
        set<char>s;
        for(int i=0;i<word.size();i++){
            if(int(word[i])>96){
                if(upper_mp.find(word[i]-32)!=upper_mp.end() && lower_mp[word[i]]<upper_mp[word[i]-32] && s.find(word[i])==s.end()){
                    count++;
                }
                s.insert(word[i]);
            }
        }

        return count;
    }
};