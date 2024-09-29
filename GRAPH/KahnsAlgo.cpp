#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter no of nodes:";
    cin >> n;
    cout << "Enter no of edges:";
    cin >> m;
    vector<vector<int>> adjList(n, vector<int>()); // If graph starts from 1 then initialize with n+1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "-> ";

        for (auto it : adjList[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    // Counting in-degree of each node.
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjList[i])
        {
            inDegree[it]++;
        }
    }
    cout << "In-degree of nodes:";
    for (int i = 0; i < n; i++)
    {
        cout << inDegree[i] << " ";
    }
    cout << endl;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    vector<int> topoSort;
    while (!q.empty())
    {
        int front = q.front();
        topoSort.push_back(front);
        q.pop();
        for (auto it : adjList[front])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    cout << "Topological Sort:";
    for (int i = 0; i < topoSort.size(); i++)
    {
        cout << topoSort[i] << " ";
    }
    return 0;
}