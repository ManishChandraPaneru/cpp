#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums(100);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);        
    }
    int count=0;
    int maxCount=0;
    for(int i=0;i<n;i++){
        if(nums[i]==maxi){
            count++;
            maxCount=max(count,maxCount);
        }
        else{
            count=0;
        }
    }
    cout<<maxCount;
    return 0;
}