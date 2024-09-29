#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int for1 = 0, for2 = 0, for3 = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for1 = for1 + a;
        for2 = for2 + b;
        for3 = for3 + c;
    }
    if (for1 == 0 && for2 == 0 && for3 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}