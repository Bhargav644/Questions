#include <bits/stdc++.h>
using namespace std;
bool sorted_or_not(int *a, int n)
{
    if (n == 1)
    {
        return true;
    }
    bool flag=sorted_or_not(a+1,n-1);
    return (a[0]<=a[1] && flag);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << sorted_or_not(a, n);
    return 0;
}