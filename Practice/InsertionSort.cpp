#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j]>current && j >= 0)
        {
            arr[j + 1]=arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    printArray(arr, n);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    InsertionSort(arr, n);
    return 0;
}