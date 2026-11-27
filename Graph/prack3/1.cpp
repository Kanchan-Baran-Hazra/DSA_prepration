// Graph implimentation with BFS and DFS traversal
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> edge;

    void helper_dfs(int src,vector<bool>& vis){
        vis[src]=true;
        cout<<src<<endl;

        for(int i=0;i<edge[src].size();i++){
            if(!vis[edge[src][i]]){
                helper_dfs(edge[src][i],vis);
            }
        }
    }

    public:
    Graph(int x){
        this->V=x;
        this->edge.resize(x);
    }

    void insert(int u,int v){
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print_g(){
        for(int i=0;i<edge.size();i++){
            cout<<i<<":";
            for(int j=0;j<edge[i].size();j++){
                cout<<edge[i][j]<<" ";
            }
            cout<<endl;
        }      
    }

    void dfs(){
        vector<bool> vis(V,false);
        helper_dfs(0,vis);
    }

    void BFS(){
        queue<int>q;
        vector<bool> mark(V,false);

        q.push(0);
        mark[0]=true;

        while(!q.empty()){
            int val=q.front();
            q.pop();

            cout<<val<<" ";

            for(int i=0;i<edge[val].size();i++){
                if(!mark[edge[val][i]]){
                    q.push(edge[val][i]);
                    mark[edge[val][i]]=true;
                }
            }
        }
    }
};


int main(){
    Graph g(6);

    g.insert(1,2);
    g.insert(1,3);
    g.insert(0,2);
    g.insert(3,4);
    g.insert(4,5);
    g.insert(4,2);

    g.print_g();

    g.dfs();

    g.BFS();
    return 0;
}