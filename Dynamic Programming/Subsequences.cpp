#include<bits/stdc++.h>
using namespace std;

//PRINTING ALL SUBSTRINGS OF A STRING
void printSubsequences(string st,vector<char> &temp,vector<vector<char>> &ans,int ind){
    if(ind<0){
        ans.push_back(temp);
        return;
    }
    temp.push_back(st[ind]);
    printSubsequences(st,temp,ans,ind-1);
    temp.pop_back();
    printSubsequences(st,temp,ans,ind-1);
}

//RECURSION
int LCS(string s1,string s2,int ind1,int ind2){
    if(ind1<0||ind2<0)return 0;
    if(s1[ind1]==s2[ind2]){
        return 1+LCS(s1,s2,ind1-1,ind2-1);
    }
    return 0+max(LCS(s1,s2,ind1-1,ind2),LCS(s1,s2,ind1,ind2-1));
}

//MEMOIZATION
int LCSMemo(string s1,string s2,int ind1,int ind2,vector<vector<int>> &dp){
    if(ind1<0||ind2<0)return 0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])return 1+LCSMemo(s1,s2,ind1-1,ind2-1,dp);
    return dp[ind1][ind2]=0+max(LCSMemo(s1,s2,ind1-1,ind2,dp),LCSMemo(s1,s2,ind1,ind2-1,dp));
}

int main(){
    string st="adcbc";
    vector<char> temp;
    vector<vector<char>> ans;
    // printSubsequences(st,temp,ans,st.size()-1);
    // for(int i=0;i<ans.size();i++){
    //     cout<<i+1<<"->";
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout << LCS("ABCBDAB", "BDCAB", 6, 4);
    vector<vector<int>> dp(3,vector<int>(3,-1));
    cout<<LCSMemo("ABC","DEF",2,2,dp);
    return 0;
}