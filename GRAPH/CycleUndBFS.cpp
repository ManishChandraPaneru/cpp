#include<bits/stdc++.h>
using namespace std;

bool detectCycleUndirectedGraphBFS(int src, vector<int> &vis, vector<vector<int>> &adjList)
{
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adjList[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cout<<"Enter no of to nodes:";
    cin>>n;
    cout<<"Enter no of edges";
    cin>>m;
    vector<vector<int>> adjList(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(auto it:adjList[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    bool ans=detectCycleUndirectedGraphBFS(1,vis,adjList);
    if(ans==true) cout<<"Cycle present";
    else cout<<"No cycle detected";
    return 0;
}