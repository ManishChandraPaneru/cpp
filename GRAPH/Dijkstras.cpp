#include <bits/stdc++.h>
using namespace std;

void dijkstras(vector<vector<pair<int, int>>> &adjList, int src, int dst, int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    vector<int> dist(V, 1e9);
    vector<int> parent(V);
    dist[src] = 0;
    parent[src] = src;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int currNode = p.second;
        int currDist = p.first;

        for (auto it : adjList[currNode])
        {
            int adjDist = it.second;
            int adjNode = it.first;
            if (currDist + adjDist < dist[adjNode])
            {
                dist[adjNode] = currDist + adjDist;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = currNode;
            }
        }
    }
    vector<int> path;
    for (int v = dst; v != src; v = parent[v])
    {
        path.push_back(v);
    }
    path.push_back(src);

    reverse(path.begin(), path.end());

    cout << "Shortest path from " << src << " to " << dst << ": ";
    for (int v : path)
    {
        cout << v << " ";
    }
    cout << endl;

    return;
}

int main()
{
    int n, e;
    cout << "Enter nodes:";
    cin >> n;
    cout << "Enter edges:";
    cin >> e;
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (auto it : adj[i])
        {
            cout << "{" << it.first << "," << it.second << "}";
        }
        cout << endl;
    }

    dijkstras(adj, 1, 3, n);

    return 0;
}