#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> rank,parent;
public:
    DisJointSet(int sizeOfSet){
        rank.resize(sizeOfSet,1);
        parent.resize(sizeOfSet);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }

    int findUltiParent(int node){
        if(parent[node]==node)return node;
        else return parent[node]=findUltiParent(parent[node]);
    }
    
    void rankBySize(int u,int v){
        int ultPv=findUltiParent(v);
        int ultPu=findUltiParent(u);

        if(rank[ultPu]<rank[ultPv])parent[ultPu]=ultPv;
        else if(rank[ultPv]<rank[ultPu])parent[ultPv]=ultPu;
        else {
            parent[ultPv]=ultPu;
            rank[ultPu]++;
        }
    }
};

int main(){
    int n;
    cout<<"Enter edges:";
    cin>>n;
    vector<pair<int,pair<int,int>>> adj;//{weight,{u,v}};
    for(int i=0;i<n;i++){
        int w,u,v;
        cin>>u>>v>>w;
        adj.push_back({w,{u,v}});
    }
    int weight=0;
    sort(adj.begin(),adj.end());
    DisJointSet ds(n+1);
    for(auto it:adj){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUltiParent(u)!=ds.findUltiParent(v)) {
            weight=weight+wt;
            ds.rankBySize(u,v);
        }
    }
    cout<<weight;

    return 0;
}

// 1 7 6
// 2 8 2
// 2 6 5
// 4 0 1
// 4 2 5
// 6 8 6
// 7 2 3
// 7 7 8
// 8 0 7
// 8 1 2
// 9 3 4
// 10 5 4
// 11 1 7
// 14 3 5