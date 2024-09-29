#include<bits/stdc++.h>
using namespace std;

//RECURSION
int matrixChainMultiplication(vector<int>&nums,int i,int j){
    if(i==j)return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=nums[i-1]*nums[k]*nums[j]+matrixChainMultiplication(nums,i,k)+matrixChainMultiplication(nums,k+1,j);
        mini=min(mini,steps);
    }
    return mini;
}

//MEMOIZATION
int matrixChainMultiplicationMemo(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==j)return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps = nums[i - 1] * nums[k] * nums[j] + matrixChainMultiplicationMemo(nums, i, k,dp) + matrixChainMultiplicationMemo(nums, k + 1, j,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}

int main(){
    vector<int> matrix={10,20,30,40};
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<matrixChainMultiplicationMemo(matrix,1,3,dp);
    return 0;
}