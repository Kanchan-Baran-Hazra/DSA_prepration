// Dijkstra's algorithm

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int val;
    int wt;

    Graph(int val, int wt)
    {
        this->val = val;
        this->wt = wt;
    }
};

void dijkastra(int src, vector<vector<Graph>> &edge){
    int n = edge.size();
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (pq.size() != 0)
    {
        pair<int, int> x = pq.top();
        pq.pop();

        for (int i = 0; i < edge[x.second].size(); i++)
        {
            if (dist[edge[x.second][i].val] > dist[x.second] + edge[x.second][i].wt)       //edge relaxation stape
            {
                dist[edge[x.second][i].val] = dist[x.second] + edge[x.second][i].wt;
                pq.push({dist[x.second] + edge[x.second][i].wt, edge[x.second][i].val});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
}

int main()
{
    vector<vector<Graph>> edge(6);

    edge[0].push_back(Graph(1, 2));
    edge[0].push_back(Graph(2, 4));

    edge[1].push_back(Graph(3, 7));
    edge[1].push_back(Graph(2, 1));

    edge[2].push_back(Graph(4, 3));

    edge[3].push_back(Graph(5, 1));

    edge[4].push_back(Graph(3, 2));
    edge[4].push_back(Graph(5, 5));

    dijkastra(0,edge);

    // for(int i=0;i<edge.size();i++){
    //     cout<<i<<":"<<endl;
    //     for(int j=0;j<edge[i].size();j++){
    //         cout<<edge[i][j].val<<endl;
    //         cout<<edge[i][j].wt<<endl;
    //     }
    //     cout<<"next"<<endl;
    // }

    return 0;
}