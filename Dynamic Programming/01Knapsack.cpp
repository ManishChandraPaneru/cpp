#include<bits/stdc++.h>
using namespace std;

//RECURSION
int knapsack(vector<int>&weight,vector<int>&value,int ind,int wt){
    if(ind<0)return 0;
    if(ind==0){
        if(weight[0]<=wt)return value[0];
        else return 0;
    }
    int pick=0;
    if(weight[ind]<=wt)pick=value[ind]+knapsack(weight,value,ind-1,wt-weight[ind]);
    int notPick=0+knapsack(weight,value,ind+-1,wt);

    return max(pick,notPick);
}

//MEMOIZATION
int knapSackMemo(vector<int> &weight,vector<int> &value,int ind,int wt,vector<vector<int>> &dp){
    if(dp[ind][wt]!=-1)return dp[ind][wt];
    if(ind<0)return 0;
    if(ind==0){
        if(weight[0]<=wt)return value[0];
        else return 0;
    }

    int pick=0;
    if(weight[ind]<=wt)pick=value[ind]+knapSackMemo(weight,value,ind-1,wt-weight[ind],dp);
    int notPick=0+knapSackMemo(weight,value,ind-1,wt,dp);

    return dp[ind][wt]= max(pick,notPick);
}

int knapSackTabulate(vector<int> &weight,vector<int> &value,int wt){
    int n=weight.size();
    vector<vector<int>> table(n,vector<int>(wt+1,0));
    for(int i=0;i<n;i++){
        if(weight[i]<=wt)table[i][0]=value[0];
        else table[i][0]=0;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<wt;j++){
            int pick=0;
            if(weight[i]<=wt)pick=value[i] + table[i-1][j];
            int notPick=table[i-1][j];

            table[i][j]=max(pick,notPick);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<wt;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> weight={3,4,5};
    vector<int> value={30,50,60};
    vector<vector<int>> dp(3,vector<int>(12,-1));
    // cout<<knapsack(weight,value,2,8);
    // cout<<knapSackMemo(weight,value,2,11,dp);
    knapSackTabulate(weight,value,8);
    return 0;
}