#include<bits/stdc++.h>
using namespace std;

int cheapestFlightKStops(int n,int src,int dst,int K,vector<vector<pair<int,int>>> &adjList){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});//{stops,{src,distance}};
    vector<int> dist(n,1e9);
    dist[src]=0;

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first;
        int currNode=it.second.first;
        int cost=it.second.second;

        if(stops>K) continue;
        for(auto it:adjList[currNode]){
            int adjNode=it.first;
            int edW=it.second;

            if(cost+edW<dist[adjNode]&&stops<=K){
                dist[adjNode]=cost+edW;
                q.push({stops+1,{adjNode,cost+edW}});
            }
        }
    }

    if(dist[src]==1e9)return -1;
    else return dist[src];
}

int main(){

}