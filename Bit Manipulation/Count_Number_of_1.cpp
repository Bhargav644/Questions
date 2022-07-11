#include <bits/stdc++.h>
using namespace std;
int Check_Numberof_One(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << Check_Numberof_One(n);
    return 0;
}