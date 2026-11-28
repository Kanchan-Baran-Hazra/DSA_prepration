class Solution {
    bool helper(int src, int dest,vector<vector<int>>& edges, vector<bool>& mark){
        if(src==dest) return true;
        mark[src]=true;

        for(int i=0;i<edges[src].size();i++){
            if(!mark[edges[src][i]]){
                if(helper(edges[src][i],dest,edges,mark)) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> mark(n,false);
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return helper(source,destination,adj,mark);
    }
};