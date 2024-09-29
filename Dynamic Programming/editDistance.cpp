#include<bits/stdc++.h>
using namespace std;

//RECURSION
int editDistance(string s,string t, int i,int j){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(s[i]==t[j])return editDistance(s,t,i-1,j-1);
    else{
        return 1+min(editDistance(s,t,i-1,j-1),min(editDistance(s,t,i-1,j),editDistance(s,t,i,j-1)));
    }
}

//MEMOIZATION
int editDistanceMemo(string s,string t, int i,int j,vector<vector<int>>&dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=editDistanceMemo(s,t,i-1,j-1,dp);
    else{
        return dp[i][j]=1+min(editDistanceMemo(s,t,i-1,j-1,dp),min(editDistanceMemo(s,t,i-1,j,dp),editDistanceMemo(s,t,i,j-1,dp)));
    }
}

int editDistanceTabulate(string s,string t){
    int n=s.length(),m=t.length();
    vector<vector<int>>table(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++)table[i][0]=i;
    for(int j=0;j<=m;j++)table[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])table[i][j]=table[i-1][j-1];
            else{
                table[i][j]=1+min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));
            }
        }
    }
    return table[n][m];
}

int main(){
    string s1="horse",s2="ros";
    // int n=s1.length(),m=s2.length();
    // cout<<editDistance(s1,s2,n-1,m-1);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // cout<<editDistanceMemo(s1,s2,n-1,m-1,dp);
    cout<<editDistanceTabulate(s1,s2);
    return 0;
}