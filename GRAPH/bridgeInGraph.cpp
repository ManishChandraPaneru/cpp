//An edge on whose removal the graph is broken into multiple components.
//Tarjan's Algorithm
//We will use two arrays time[](DFS time tarversal or the time at which you reach a node) and lowestTime[](minimum lowest time insertion of all adjacent nodes apart from parent.)

#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<vector<int>> &adjList,vector<int> &low,vector<int>&timeV,vector<int> &vis,int &time){
    vis[src]=1;
    time=time+1;
    timeV[src]=low[src]=time;
    for(auto it:adjList[src]){
        if(!vis[it])dfs(it,adjList,timeV,vis,time);
    }
}

int main(){
    int n,m;
    cout<<"Enter no of nodes:";
    cin>>n;
    cout<<"Enter no of edges:";
    cin>>m;
    vector<vector<int>> adjList(n+1,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> timeV(n+1,0),vis(n+1,0),low(n+1,0);

    // for(int i=1;i<n;i++){
    //     cout<<i<<"->";
    //     for(auto it:adjList[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<""<<endl;
    // }
    int time=0;
    dfs(1,adjList,low,timeV,vis,time);
    for(int i=1;i<timeV.size();i++){
        cout<<timeV[i]<<" ";
    }
    return 0;
}

// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 9
// 6 9
// 8 10
// 10 11
// 10 12
// 11 12