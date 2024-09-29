#include<bits/stdc++.h>
using namespace std;

void sortUsingDFS(int src,vector<vector<int>> &adjList,vector<int> &vis,stack<int> &st){
    vis[src]=1;
    for(auto it:adjList[src]){
        if(!vis[it])sortUsingDFS(it,adjList,vis,st);
    }
    st.push(src);
    return;
}

vector<vector<int>> reverseGraph(vector<vector<int>> &adjList)
{
    int n = adjList.size();
    vector<vector<int>> reversedGraph(n, vector<int>());
    for (int i = 0; i < adjList.size(); i++)
    {
        for (auto it : adjList[i])
        {
            reversedGraph[it].push_back(i);
        }
    }
    return reversedGraph;
}

void dfs(int src,vector<vector<int>> &adjList,vector<int> &vis,vector<int> &temp){
    vis[src]=1;
    temp.push_back(src);
    for(auto it:adjList[src]){
        if(!vis[it])dfs(it,adjList,vis,temp);
    }
}


int main(){
    int n,m;
    cout<<"Enter no of nodes:";
    cin>>n;
    cout<<"Enter no of edges:";
    cin>>m;
    vector<vector<int>> adjList(n,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    };
    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i])sortUsingDFS(i,adjList,vis,st);
    }
    fill(vis.begin(),vis.end(),0);
    vector<vector<int>> reversedGraph=reverseGraph(adjList);
    int count=0;
    vector<vector<int>> ans;
    while(!st.empty()){
        int src=st.top();
        st.pop();
        vector<int> temp;
        if(!vis[src]){
            count++;
            dfs(src,reversedGraph,vis,temp);
            }
        ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        cout<<"{";
       for(auto it:ans[i]){
        cout<<it<<" ";
       }
       cout<<"}"<<endl;
    }
    cout<<count;
    return 0;
}