#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int amazing=0;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    int best=temp[0],worst=temp[0];
    for(int i=0;i<n;i++){
        if(temp[i]>best){
            amazing++;
            best=temp[i];
        }
        if(temp[i]<worst){
            amazing++;
            worst=temp[i];
        }
    }
    cout<<amazing;
    return 0;
}