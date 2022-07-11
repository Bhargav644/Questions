#include <bits/stdc++.h>
using namespace std;
int Find_Unique(int a[], int n)
{
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        Xor=Xor^a[i];
    }
    return Xor;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Find_Unique(arr, n);
    return 0;
}