#include<bits/stdc++.h>
using namespace std;

//RECURSION
int subSetSumK(vector<int> &nums,int ind,int target){
    if(ind<0)return 0;
    if(ind==0){
        if(nums[0]==target)return 1;
        else return 0;
    }
    if(target==0)return 1;
    int take=0;
    if(target>=nums[ind])take=subSetSumK(nums,ind-1,target-nums[ind]);
    int notTake=subSetSumK(nums,ind-1,target);

    return take+notTake;
}

int main(){
    vector<int> nums={1,2,1,3};
    cout<<subSetSumK(nums,3,2);
    return 0;
}