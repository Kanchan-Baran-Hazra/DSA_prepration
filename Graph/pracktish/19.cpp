// No of provences

// This approach is not applicable because thare could be the indiret connection and also the graph representation should be in the form of ajdList
#include <bits/stdc++.h>
using namespace std;

void helper(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &mark, int &count, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || mark[i][j] || !grid[i][j])
        return;

    mark[i][j] = true;

    helper(i + 1, j, grid, mark, count, n, m);
    helper(i - 1, j, grid, mark, count, n, m);
    helper(i, j + 1, grid, mark, count, n, m);
    helper(i, j - 1, grid, mark, count, n, m);
}

void noOfprov(vector<vector<int>> &grid, vector<vector<bool>> &mark)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !mark[i][j])
            {
                helper(i, j, grid, mark, count, n, m);
                count++;
            }
        }
    }

    cout << "No of provience is:" << count << endl;
}

// int main(){
//     // cout<<"hello";
//     vector<vector<int>> grid={{1,1,0,0,},{1,1,0,0},{0,0,1,1},{0,0,1,1}};
//     int n=grid.size();
//     vector<vector<bool>> mark(n,vector<bool>(n,false));
//     noOfprov(grid,mark);
//     return 0;
// }

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

    void addedge(int u, int v)
    {
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < edge.size(); i++)
        {
            cout << i << ":";
            for (int j = 0; j < edge[i].size(); j++)
            {
                cout << edge[i][j] << " ";
            }
            cout << endl;
        }
    }

    void helper(int src, vector<bool> &mark)
    {
        cout << src << endl;
        mark[src] = true;

        for (int i = 0; i < edge[src].size(); i++)
        {
            if (!mark[edge[src][i]])
                helper(edge[src][i], mark);
        }
    }

    void DFS()
    {
        int count = 0;
        vector<bool> mark(V, false);
        for (int i = 0; i < edge.size(); i++)
        {
            if (!mark[i])
            {
                helper(i, mark);
                count++;
            }
        }

        cout << "provence:" << count << endl;
    }
};

int main()
{
    // cout<<"hello";
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(2, 3);

    g.DFS();
    return 0;
}
