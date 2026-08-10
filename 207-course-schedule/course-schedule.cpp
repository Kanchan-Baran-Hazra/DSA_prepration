class Solution {
public:
    static bool helper(int src, vector<vector<int>>& prerequisites,vector<bool> &mark,vector<bool> &recstack){
        mark[src]=true;
        recstack[src]=true;

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            if(u==src){
                if(!mark[v]){
                    if(helper(v,prerequisites,mark,recstack)) return true;
                }else if(recstack[v]) return true;
            }
        }

        recstack[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>mark(numCourses,false);
        vector<bool>recstack(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(helper(i,prerequisites,mark,recstack)) return false;
        }

        return true;
    }
};