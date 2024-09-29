#include<bits/stdc++.h>
using namespace std;

//RECURSION
int maxSumNonAdjacent(int ind,vector<int> &nums){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;

    int pick= nums[ind]+maxSumNonAdjacent(ind-2,nums);
    int notPick=0+maxSumNonAdjacent(ind-1,nums);
    return max(pick,notPick);
}

//MEMOIZATION
int maxSumNonAdjacentMemo(int ind,vector<int> &nums,vector<int> &dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+maxSumNonAdjacentMemo(ind-2,nums,dp);
    int notPick=0+maxSumNonAdjacentMemo(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}


int main(){
    vector<int> nums={2,1,4,9,9,9,9,9};
    int n=nums.size();
    vector<int> dp(n,-1);
    cout<<maxSumNonAdjacentMemo(7,nums,dp)<<endl;
   
    return 0;
}