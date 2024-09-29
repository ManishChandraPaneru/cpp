#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n+1;i++){
        if(i==0||i==2*n){
            for(int j=0;j<n;j++)cout<<" ";
            cout<<0;
            cout<<endl;
        }
        else if(i>0&&i<=n){
            for(int j=0;j<abs(n-i);j++)cout<<" ";
            cout<<0<<" ";
            for(int j=1;j<=i;j++)cout<<j;
            for(int j=i-1;j>=0;j++)cout<<j;
            cout<<endl;
        }
        else{
            for (int j = 0; j < abs(n - i); j++)cout << " ";
            cout << 0 << " ";
            for(int j=i-n;j)
        }
    }
    return 0;
}