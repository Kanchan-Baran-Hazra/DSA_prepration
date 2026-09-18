#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<pair<int,int>>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v,int x){
        edge[u].push_back({x,v});
    }

    void dijkstra(int i,vector<int>& dis){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        
        while (q.size()!=0){
            pair<int,int> el=q.top();
            q.pop();

            int s_wt=el.first;
            int s_val=el.second;

            for(int i=0;i<edge[s_val].size();i++){
                int wt=edge[s_val][i].first;
                int val=edge[s_val][i].second;

                if(dis[val]>s_wt+wt){
                    dis[val]=s_wt+wt;
                }
                q.push({s_wt+wt,val});
            }
        }
        
    }
};

int main(){
    // cout<<"hello";
    Graph g(6);
    vector<int> dis(g.V,INT_MAX);
    dis[0]=0;          // distance from won is 0

    g.addEdge(0,1,2);  // 0 ---> 1(2)
    g.addEdge(0,2,4);  // 0 ---> 2(4)
    g.addEdge(1,2,1);  // 1 ---> 2(1)
    g.addEdge(1,3,7);  // 1 ---> 3(7)
    g.addEdge(2,4,3);  // 2 ---> 4(3)
    g.addEdge(4,3,2);  // 4 ---> 3(2)
    g.addEdge(3,5,1);  // 3 ---> 5(1)
    g.addEdge(4,5,5);  // 4 ---> 5(5)

    g.dijkstra(0,dis);

    for(int i=0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }

    return 0;
}


