#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(100);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int maxi = -1e9, mini = 1e9;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxi)
        {
            x = i;
            maxi = nums[i];
        }
        if (nums[i] <= mini)
        {
            y = i;
            mini = nums[i];
        }
    }
    if (nums[0] == maxi && nums[n - 1] == mini)
    {
        cout << 0;
        return 0;
    }
    int swaps = (x - 0) + (n - 1 - y);
    if (x > y)
        swaps--;
    cout << swaps;
    return 0;
}
