#include<bits/stdc++.h>
using namespace std;

void reverseGraph(vector<vector<int>> &adjList){
    int n=adjList.size();
    vector<vector<int>> reversedGraph(n,vector<int>());
    for(int i=0;i<adjList.size();i++){
        for(auto it: adjList[i]){
            reversedGraph[it].push_back(i);
        }
    }

    for (int i = 0; i < reversedGraph.size(); i++)
    {
        cout << i << "->";
        for (auto it : reversedGraph[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return;
}

int main(){
    int n,m;
    cout<<"Enter nodes:";
    cin>>n;
    cout<<"Enter edges:";
    cin>>m;
    vector<vector<int>> adjList(n,vector<int>());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    for(int i=0;i<adjList.size();i++){
        cout<<i<<"->";
        for(auto it:adjList[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    reverseGraph(adjList);
    return 0;
}

// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 4 7
// 4 5
// 5 6
// 6 4
// 6 7