#include<bits/stdc++.h>
using namespace std;

//RECURSION
int minFallingPathSum(vector<vector<int>> grid,int i,int j,int rows,int cols){
    if(i>=rows||j>=cols||j<0)return 1e9;
    if(i==rows-1)return grid[rows-1][j];

    int diagL=grid[i][j]+minFallingPathSum(grid,i+1,j-1,rows,cols);
    int down=grid[i][j]+minFallingPathSum(grid,i+1,j,rows,cols);
    int diagR=grid[i][j]+minFallingPathSum(grid,i+1,j+1,rows,cols);

    return min(diagL,min(diagR,down));
}

//MEMOIZATION
int minFallingPathSumMEMO(vector<vector<int>> grid, int i, int j, int rows, int cols,vector<vector<int>>&dp)
{
    if (i >= rows || j >= cols || j < 0)return 1e9;
    if (i == rows - 1)return grid[rows - 1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int diagL = grid[i][j] + minFallingPathSumMEMO(grid, i + 1, j - 1, rows, cols,dp);
    int down = grid[i][j] + minFallingPathSumMEMO(grid, i + 1, j, rows, cols,dp);
    int diagR = grid[i][j] + minFallingPathSumMEMO(grid, i + 1, j + 1, rows, cols,dp);

    return dp[i][j]=min(diagL, min(diagR, down));
}

int minFallingPathSumTABULATE(vector<vector<int>>grid){
    int n=grid.size();
    vector<vector<int>> tabulate(n,vector<int>(n));
   
}

int main(){
    vector<vector<int>> grid={{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> dp(grid.size(),vector<int>(grid.size(),-1));
    int mini=INT_MAX;
    for(int i=0;i<grid.size();i++){
        // int ans=minFallingPathSum(grid,0,i,3,3);
        int ans=minFallingPathSumMEMO(grid,0,i,3,3,dp);
        mini=min(mini,ans);
    }
    cout<<mini;
    return 0;
}