#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v){
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<":"<<" ";
            for(int j=0;j<edge[i].size();j++){
                cout<<edge[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void bfs_helper(int x,vector<bool>& mark){
        queue<int> q;
        q.push(x);
        mark[x]=true;

        while (q.size()!=0){
            int el=q.front();
            q.pop();
            cout<<el<<" ";

            for(int i=0;i<edge[el].size();i++){
                if(!mark[edge[el][i]]){
                    q.push(edge[el][i]);
                    mark[edge[el][i]]=true;
                }
            }
        }
    }

    void BFS(){
        vector<bool> mark(V,false);

        for(int i=0;i<V;i++){
            if(!mark[i]){
                bfs_helper(i,mark);
            }
        }
    }

    void dfs_helper(int x,vector<bool>& mark){
        cout<<x<< " ";
        mark[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                dfs_helper(edge[x][i],mark);
            }
        }
    }

    void DFS()
    {
        vector<bool> mark(V,false);

        for (int i = 0; i < V; i++)
        {
            if (!mark[i])
            {
                dfs_helper(i, mark);
            }
        }
    }


    bool cycle_dfs_helper(int x,vector<bool>& mark,int par){
        mark[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                return cycle_dfs_helper(edge[x][i],mark,x);
            }else if(par!=INT_MAX && edge[x][i]!=par){
                return true;
            }
        }

        return false;
    }

    bool cycle_bfs_helper(int n,vector<bool>& mark){
        queue<pair<int,int>> q;
        q.push({n,INT_MAX});
        mark[n]=true;

        while (q.size()!=0){
            pair<int,int> x=q.front();
            int el=x.first;
            int par=x.second;
            q.pop();

            for(int i=0;i<edge[el].size();i++){
                if(!mark[edge[el][i]]){
                    q.push({edge[el][i],el});
                    mark[edge[el][i]]=true;
                }else if(par!=INT_MAX && edge[el][i]!=par){
                    return true;
                }
            }
        }
        return false;
    }

    void cycle_detect(bool dfs){
        vector<bool> mark(V,false);
        if(dfs){
            for(int i=0;i<V;i++){
                if(!mark[i]){
                    if(cycle_dfs_helper(i,mark,INT_MAX)){
                        cout<<"Cycle detected..!"<<endl;
                        break;
                    }
                    else cout<<"Not detected..";
                }
            }
        }else{
            for(int i=0;i<V;i++){
                if(!mark[i]){
                    if(cycle_bfs_helper(i,mark)){
                        cout<<"Cycle detected..!"<<endl;
                        break;
                    }
                    else cout<<"Not detected..";
                }
            }
        }
    }


    

};

int main(){
    // cout<<"hello"<<endl;
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);

    // g.print();

    // g.BFS();

    // g.DFS();

    g.cycle_detect(0);



    return 0;
}