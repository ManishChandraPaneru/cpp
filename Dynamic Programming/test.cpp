#include<bits/stdc++.h>
using namespace std;

//  vector<vector<int>> LCSTabulate(string s1,string s2){
//         int n=s1.length(),m=s2.length();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp;
//     }

int main(){
    string s1="zbax";
    string ans="";
    vector<int> ans1;
    for(int i=0;i<s1.size();i++){
        ans1.push_back(s1[i]-'a'+1);
    }
   int num=ans1[0];
   for(int i=1;i<ans1.size();i++){
    if(ans1[i]<10){
        num=num*10;
        num=num+ans1[i];
    }
    else{
        num=num*100;
        num=num+ans1[i];
    }
   }
   int sum;
   for(int i=0;i<2;i++){
        sum=0;
        while(num!=0){
            sum=sum+num%10;
            num=num/10;
            cout<<sum<<" ";
        }
        num=sum;
   }
   cout<<sum;
    return num;
}