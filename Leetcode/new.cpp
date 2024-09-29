#include<bits/stdc++.h>
using namespace std;

void maxScore(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        vector<bool> helper(b.size(), false);
        for (int i = 0; i < 4; i++)
        {
            int maxInd = -1;
            int maxi = -1e9;
            for (int j = 0; j < b.size(); j++)
            {
                if (j > maxInd && b[j] > maxi && helper[j] == false)
                {
                    maxInd = j;
                    maxi = b[j];
                }
            }
            helper[maxInd] = true;
            ans.push_back(maxi);
        }
        for (int i = 0; i < 4; i++)
        {
            cout << ans[i] << " ";
        }
        return ;
    }

    int main(){
        vector<int> a={3,2,5,6};
        vector<int> b = {2, -6, 4, -5, -3, 2, -7};
        maxScore(a,b);
        return 0;
    }