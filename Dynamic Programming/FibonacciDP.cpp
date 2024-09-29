#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){
    if(n==0||n==1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    
}

/*int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
}*/

int main(){
/*    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=0,dp[1]=1;
    for(int i=2;i<dp.size();i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
*/
    int n;
    cin>>n;
    int dp1=0,dp2=1,ans=0;
    for(int i=0;i<n-1;i++){
        ans=dp1+dp2;
        dp1=dp2;
        dp2=ans;
    }
    cout<<ans;

    return 0;
}