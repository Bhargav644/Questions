#include <bits/stdc++.h>
using namespace std;

int frequentElement(int a[], int n)
{
    int max_Elelment = -99999;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_Elelment)
        {
            max_Elelment = a[i];
        }
    }
    int newarray[max_Elelment];
    for (int i = 0; i < max_Elelment+1; i++)
    {
        newarray[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        newarray[a[i]] += 1;
    }
    int max_count = -99999;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (newarray[a[i]] > max_count)
        {
            max_count = newarray[a[i]];
            index = a[i];
        }
    }
    if (max_count > (n / 2))
    {
        return index;
    }
    return -1;
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
    cout << frequentElement(arr, n);
    return 0;
}
