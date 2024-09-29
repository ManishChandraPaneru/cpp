#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,rank;
    public:
    DisjointSet(int size){
        parent.resize(size+1);
        rank.resize(size+1,1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node]==node)return node;
        else return parent[node]=findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ult_Pv=findUltimateParent(v);
        int ult_Pu=findUltimateParent(u);
        if(rank[ult_Pu]<rank[ult_Pv]) parent[ult_Pu]=ult_Pv;
        else if (rank[ult_Pv] < rank[ult_Pu])
            parent[ult_Pv] = ult_Pu;
        else{
            parent[ult_Pu]=ult_Pv;
            rank[ult_Pv]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    //If 3 and 7 are same or not.
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7))cout<<"Same";
    else cout<<"Not same";
    cout<<endl;
    ds.unionByRank(3,7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Same";
    else cout << "Not same";

    return 0;
}