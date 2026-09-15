#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<int>> edge;

    Graph(int n)
    {
        this->V = n;
        this->edge.resize(n);
    }

    void addEdge(int u, int v)
    {
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << ":" << " ";
            for (int j = 0; j < edge[i].size(); j++)
            {
                cout << edge[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs_helper(int x, vector<bool> &mark)
    {
        queue<int> q;
        q.push(x);
        mark[x] = true;

        while (q.size() != 0)
        {
            int el = q.front();
            q.pop();
            cout << el << " ";

            for (int i = 0; i < edge[el].size(); i++)
            {
                if (!mark[edge[el][i]])
                {
                    q.push(edge[el][i]);
                    mark[edge[el][i]] = true;
                }
            }
        }
    }

    void BFS()
    {
        vector<bool> mark(false, V);

        for (int i = 0; i < V; i++)
        {
            if (!mark[i])
            {
                bfs_helper(i, mark);
            }
        }
    }

    void dfs_helper(int x, vector<bool> &mark)
    {
        cout << x << " ";
        mark[x] = true;

        for (int i = 0; i < edge[x].size(); i++)
        {
            if (!mark[edge[x][i]])
            {
                dfs_helper(edge[x][i], mark);
            }
        }
    }

    void DFS()
    {
        vector<bool> mark(false, V);

        for (int i = 0; i < V; i++)
        {
            if (!mark[i])
            {
                dfs_helper(i, mark);
            }
        }
    }
};

int main()
{
    // cout<<"hello"<<endl;
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    // g.print();

    // g.BFS();

    g.DFS();

    return 0;
}