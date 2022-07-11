#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Subset(int a[], int n)
{
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
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
    Subset(arr, n);
    return 0;
}