// Graph implimentation with BFS and DFS traversal
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> edge;

    bool helper_has_cycle(int src,int par,vector<bool>& mark){
        mark[src]=true;

        for(int i=0;i<edge[src].size();i++){
            if(!mark[edge[src][i]]){
                return helper_has_cycle(edge[src][i],src,mark);
            }else if(edge[src][i]!=par) return true; 
        }

        return false;
    }

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

    bool has_cycle(){
        vector<bool> mark(V,false);
        return helper_has_cycle(0,-1,mark);
    }


    bool has_cycle_bfs(){
        vector<bool> mark(V,false);
        queue<pair<int,int>>q;
        q.push({0,-1});

        
    }
};


int main(){
    Graph g(4);

    g.insert(0,1);
    g.insert(1,2);
    g.insert(2,3);

    g.print_g();

    g.dfs();

    g.BFS();
    cout<<endl;
    cout<<g.has_cycle();
    return 0;
}