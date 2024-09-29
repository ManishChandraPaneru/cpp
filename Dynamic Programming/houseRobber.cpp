#include<bits/stdc++.h>
using namespace std;

//RECURSIVE
int maximumSumNonAdjacentElements(int ind,vector<int>&nums,vector<int> &dp){
    if(ind==0)return nums[0];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int pick=nums[ind]+maximumSumNonAdjacentElements(ind-2,nums,dp);
    int notPick=0+maximumSumNonAdjacentElements(ind-1,nums,dp);
    return dp[ind]=max(pick,notPick);
}

int main(){
    vector<int> nums={1,3,2,1};
    vector<int> temp1,temp2;
    for(int i=0;i<nums.size();i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=nums.size()-1)temp2.push_back(nums[i]);
    }
    vector<int> dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);
    cout<<max(maximumSumNonAdjacentElements(temp1.size()-1,temp1,dp1),maximumSumNonAdjacentElements(temp2.size(),temp2,dp2));
    return 0;
}