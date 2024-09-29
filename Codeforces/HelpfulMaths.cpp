#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;;
    cin>>str;;
    string s="";
    int one=0,two=0,three=0;
    for(int i=0;i<str.size();i=i+2){
        if(str[i]=='1')one++;
        else if(str[i]=='2')two++;
        else three++;
    }
    cout<<one<<" "<<two<<" "<<three;
    cout<<endl;
    for(int i=0;i<one;i++){
        s.append("1+");
    }
    for (int i = 0; i < two; i++)
    {
            s.append("2+");
    }
    for (int i = 0; i < three; i++)
    {
        if (i == three - 1)
            s.append("3");
        else
            s.append("3+");
    }
    cout<<s;
    return 0;
}