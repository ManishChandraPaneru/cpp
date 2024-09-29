#include<bits/stdc++.h>
using namespace std;

int cherryPickupReturn(vector<vector<int>> &grid, int i, int j);

    int cherryPickup(vector<vector<int>> &grid, int i, int j, int n)
{
    if(i==n-1&&j==n-1){
        return cherryPickupReturn(grid,i,j);
    }
    if(grid[i][j]==-1||i>=n||j>=n)return -1e9;
    int cherries=grid[i][j];
    grid[i][j]=0;
    int down=cherries+cherryPickup(grid,i+1,j,n);
    int diag=cherries+cherryPickup(grid,i,j+1,n);
    grid[i][j]=cherries;

    return max(down,diag);
}

int cherryPickupReturn(vector<vector<int>> &grid,int i,int j){
    if(i==0&&j==0)return 0;
    if(i<0||j<0||grid[i][j]==-1)return -1e9;

    int cherries=grid[i][j];
    grid[i][j]=0;
    int up=cherries+cherryPickupReturn(grid,i-1,j);
    int diag=cherries+cherryPickupReturn(grid,i,j-1);
    grid[i][j]=cherries;

    return max(up,diag);
}

int main(){
    vector<vector<int>> grid={{0,1,-1},{1,0,-1},{1,1,1}};
    cout<<cherryPickup(grid,0,0,3);
    return 0;
}