#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<"->";
        for (auto it : adjList[i])
        {
            cout << it << " ";
        }
        cout<<endl;
    }
}

//