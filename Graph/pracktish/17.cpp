// Disjoint set union

#include <bits/stdc++.h>
using namespace std;

class Disjoint_set_Union
{
public:
    int n;
    vector<int> par, rank;

    Disjoint_set_Union(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void union_byRank(int a, int b)
    {
        int parA = find_par(a);
        int parB = find_par(b);

        if (parA == parB)
            return;
        else if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] < rank[parB])
        {
            par[parA] = parB;
        }
        else
        {
            par[parB] = parA;
        }
    }

    int find_par(int x)
    {
        if (par[x] == x)
            return x;

        return par[x]=find_par(par[x]);
    }

    void getinfo()
    {
        for (int i = 0; i < n; i++)
        {
            cout << par[i] << " " ;
            cout << rank[i] << " " << endl;
        }
    }
};

int main()
{
    // cout<<"hello";

    Disjoint_set_Union d(6);
    d.union_byRank(0, 2);
    d.union_byRank(1, 3);
    d.union_byRank(2, 5);
    d.union_byRank(0, 3);
    d.union_byRank(0, 4);

    d.getinfo();

    return 0;
}