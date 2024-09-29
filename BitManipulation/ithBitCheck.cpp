#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    if((n&(1<<m))!=0)cout<<"Set";
    else cout<<"Not Set";
    return 0;
}