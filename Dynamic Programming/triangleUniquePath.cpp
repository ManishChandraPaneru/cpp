#include<bits/stdc++.h>
using namespace std;

//RECURSION
int triangleMinPath(vector<vector<int>> triangle,int n,int i,int j){
    int m=triangle[i].size();
    if(i==n)return 1e9;
    if(j>m-1)return 1e9;
    if(i==n-1)return triangle[i][j];
    int down=triangle[i][j] + triangleMinPath(triangle, n, i + 1, j);
    int diagonal=triangle[i][j]+triangleMinPath(triangle,n,i+1,j+1);

    return min(down,diagonal);
}

//MEMOIZATION
int triangleMinPathMemo(vector<vector<int>> triangle,int n,int i,int j,vector<vector<int>> &dp){
    int m=triangle[i].size();
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n)return 1e9;
    if(j>m-1)return 1e9;
    if(i==n-1)return triangle[i][j];
    int down=triangle[i][j] + triangleMinPathMemo(triangle, n, i + 1, j,dp);
    int diagonal=triangle[i][j]+triangleMinPathMemo(triangle,n,i+1,j+1,dp);

    return dp[i][j]=min(down,diagonal);
}

//TABULATION
int triangleMinPathTabulate(vector<vector<int>>triangle){
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n));
    for(int j=0;j<triangle.size();j++)dp[n-1][j]=triangle[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+dp[i+1][j];
            int diagonal=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,diagonal);
        }
    }
    return dp[0][0];
}

int main(){
    vector<vector<int>> triangle={{2},{3,4},{5,6,7},{4,1,8,3}};
    int n = triangle.size();
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++){
        int size=triangle[i].size();
        dp[i]=vector<int>(size,-1);
    }
    // cout<<triangleMinPath(triangle,4,0,0);
    // cout<<triangleMinPathMemo(triangle,4,0,0,dp);
     cout<<triangleMinPathTabulate(triangle);

    return 0;
}