#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>&grid,int i,int j){
    if(i==0&&j==0)return grid[0][0];
    if(i<0||j<0)return 1e9;

    int up=1e9;
    int left=1e9;
    if (i > 0)left = grid[i][j] + minPathSum(grid, i - 1, j);
    if(j>0)up=grid[i][j]+minPathSum(grid,i,j-1);

    return min(left,up);
}

int main(){
    vector<vector<int>> grid = {{ 1, 3, 1 },{ 1, 5, 1 },{ 4, 2, 1 }};
    cout<<minPathSum(grid,2,2);
    return 0;
}