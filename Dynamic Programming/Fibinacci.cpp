#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0||n==1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter N ";
    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}