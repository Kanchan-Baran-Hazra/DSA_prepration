#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    // Your code here
    if (start.size() == 0)
        return 0;
    vector<pair<int, int>> par_vec;
    for (int i = 0; i < start.size(); i++)
    {
        pair<int, int> temp;
        temp.first = start[i];
        temp.second = end[i];
        par_vec.push_back(temp);
    }
    sort(par_vec.begin(), par_vec.end(), cmp);

    for(auto i:par_vec){
        cout<<i.first<<" "<<i.second<<endl;
    }

    int count = 1;
    int prev = 0;
    // for (int i = 1; i < par_vec.size(); i++)
    // {
    //     if (par_vec[prev].second < par_vec[i].first)
    //     {
    //         count++;
    //         prev = i;
    //     }
    // }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start, end) << endl;
    return 0;
}