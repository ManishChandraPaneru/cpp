#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int xorVar=0;
        for(int i=0;i<n;i++){
            xorVar^=nums[i];
        }
        int ans=xorVar/n;
        cout<<"ans-"<<xorVar<<endl;
        
    }
    return 0;
}