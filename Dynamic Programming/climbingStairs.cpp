#include<bits/stdc++.h>
using namespace std;

//RECURSIVE SOLUTION
int climbingStairs(int n){
    if(n==0)return 1;
    if(n<0)return 0;
    else return climbingStairs(n-1)+climbingStairs(n-2);
}

//MEMOIZATION SOLUTION
int climbingStairsMemo(int n,vector<int> &dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    else return dp[n]=climbingStairsMemo(n-1,dp)+climbingStairsMemo(n-2,dp);
}

//TABULATION
int climbingStairsTabulate(int n){
    vector<int> tabulate(n);
    tabulate[0]=1;
    tabulate[1]=1;
    for(int i=2;i<=n;i++){
        tabulate[i]=tabulate[i-1]+tabulate[i-2];
    }
    for(int i=0;i<n;i++){
        cout<<tabulate[i]<<" ";
    }
    return tabulate[n];
}

int main(){
    int n;
    cout<<"Enter number of stairs:";
    cin>>n;
    vector<int> dp(n+1,-1);
    // cout<<climbingStairs(n);
    // cout<<climbingStairsMemo(n,dp);
    cout<<climbingStairsTabulate(n);


    return 0;
}

