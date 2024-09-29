#include<bits/stdc++.h>
using namespace std;

//RECURSION
int gridUniquePaths(int n,int m,int i,int j){
    if(i==n-1&&j==m-1)return 1;
    if(i>=n)return 0;
    if(j>=m)return 0;

    int right=gridUniquePaths(n,m,i+1,j);
    int down=gridUniquePaths(n,m,i,j+1);

    return right+down;
}

//MEMOIZATION
int gridUniquePathsMemoization(int rows,int columns,int i,int j,vector<vector<int>> &dp){
    if(i==rows-1&&j==columns-1)return 1;
    if (i>=rows)return 0;
    if(j>=columns)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int right=gridUniquePathsMemoization(rows,columns,i+1,j,dp);
    int down=gridUniquePathsMemoization(rows,columns,i,j+1,dp);

    return dp[i][j]=right+down;
}

int main(){
    int rows=2,columns=3;
    vector<vector<int>> dp(rows,vector<int>(columns,-1));
    // cout<<gridUniquePaths(rows,columns,0,0);
    // cout<<gridUniquePathsMemoization(rows,columns,0,0,dp);

    return 0;
}