class Solution {
    vector<string> helper(string s,char c,unordered_map<string,int>& mp,unordered_map<string,int>& mark){
        vector<string> ans;

        for(int i=0;i<s.size();i++){
            string s1=s;
            s1[i]=c;
            if(mp.find(s1)!=mp.end() && mark.find(s1)==mark.end()){
                ans.push_back(s1);
            }
        }
        return ans;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int> mp;
        for(int i=0;i<bank.size();i++){
            mp[bank[i]]++;
        }
        unordered_map<string,int> mark;
        int count=0;

        vector<char> choice;
        choice.push_back('A');
        choice.push_back('C');
        choice.push_back('G');
        choice.push_back('T');

        queue<pair<string,int>> q;
        q.push({startGene,0});
        mark[startGene]++;

        while(q.size()!=0){
            auto m=q.front();
            string x=m.first;
            int x1=m.second;
            q.pop();
            if(x==endGene) return x1;

            for(int i=0;i<4;i++){
                vector<string> options=helper(x,choice[i],mp,mark);
                for(int i=0;i<options.size();i++){
                    q.push({options[i],x1+1});
                    mark[options[i]]++;
                }
            }
            // count++;
        }
        return -1;
    }
};