#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row = -1, col = -1;
    vector<vector<int>> nums(5, vector<int>(5));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>nums[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (nums[i][j] == 1)
            {
                row = i + 1, col = j + 1;
            }
        }
    }
    cout << abs(row - col);
    return 0;
}