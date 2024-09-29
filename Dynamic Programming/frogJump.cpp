#include<bits/stdc++.h>
using namespace std;

//RECURSIVE SOLUTION
int frogJump(int ind,vector<int> &heights){
    if(ind==0)return 0;
    if(ind<0)return INT_MAX;
    int left=frogJump(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
    int right=frogJump(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
    return min(left,right);
}

//MEMOIZATION
int frogJumpMemo(int ind,vector<int> &heights,vector<int> &dp){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=frogJumpMemo(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if (ind > 1)right=frogJumpMemo(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind]=min(left,right);
}

//TABULATION
// int frogJumpTabulation(vector<int> &heights){
//     int n=heights.size();
//     vector<int> tabulate(n);

// }

int main(){
    vector<int> heights = {30,10,60,10,60,50};
    int size=heights.size();
    vector<int> dp(size,-1);
    int ans=frogJumpMemo(size-1,heights,dp);
    cout<<ans;
    return 0;
}