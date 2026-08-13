class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        int i=0;
        int j=0;
        while(i<n || j<m){
            string temp1="";
            string temp2="";
            while(i<n && v1[i]!='.'){
                temp1.push_back(v1[i]);
                i++;
            }
            i++;
            while(j<m && v2[j]!='.'){
                temp2.push_back(v2[j]);
                j++;
            }
            j++;
            int x = temp1.empty() ? 0 : stoi(temp1);
            int y = temp2.empty() ? 0 : stoi(temp2);
            if(x<y) return -1;
            if(y<x) return 1;
        }
        return 0;
    }
};