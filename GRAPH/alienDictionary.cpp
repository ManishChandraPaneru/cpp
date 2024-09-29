#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V,vector<vector<int>> adjList){
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adjList[i]){
            inDegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0)q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int front=q.front();
        topo.push_back(front);
        q.pop();
        for(auto it:adjList[front]){
            inDegree[it]--;
            if(inDegree[it]==0)q.push(it);
        }
    }
    return topo;
}

string findOrder(string dict[],int N,int K){
    vector<vector<int>> adj(K,vector<int>());
    for(int i=0;i<N-1;i++){
        string str1=dict[i];
        string str2=dict[i+1];
        int len=min(str1.size(),str2.size());
        for(int ptr=0;ptr<len;ptr++){
            if(str1[ptr]!=str2[ptr]){
                adj[str1[ptr] - 'a'].push_back(str2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo=topoSort(K,adj);
    string ans="";
    for(auto it:topo){
        ans=ans+char(it+'a');
    }
    return ans;
}

int main(){

}