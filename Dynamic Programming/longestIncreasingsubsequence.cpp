#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,int ind,int prev,int n){
    if(ind==n){
        if(nums[n]>nums[n-1])return 1;
        else return 0;
    }
    int take=0;
    if(nums[ind]>prev)take=1+solve(nums,ind+1,nums[ind],n);
    int notTake=solve(nums,ind+1,prev,n);

    return max(take,notTake);
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n=nums.size();
    cout<<solve(nums,0,10,n-1);
    return 0;
}