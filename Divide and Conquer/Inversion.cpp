// basically a steps need to sort an unsorted array
//  or in mathematically A[i]>Aj] where i<j
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
int mergeSort(int[], int, int, int);
int findInversions(int A[], int start, int end)
{
    int mid, inv_count = 0;
    if (start < end)
    {
        mid = (end + start) / 2;
        inv_count += findInversions(A, start, mid);
        inv_count += findInversions(A, mid + 1, end);
        inv_count += mergeSort(A, start, mid + 1, end);
    }
    return inv_count;
}
int mergeSort(int A[], int left, int mid, int right)
{
    int inv_count = 0;
    int temp[right + 1];
    int i = left, j = mid, k = left;
    while (i <= mid - 1 and j <= right)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = A[i++];
    while (j <= right)
        temp[k++] = A[j++];
    for (i = left; i <= right; i++)
        A[i] = temp[i];

    return inv_count;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int A[] = {1, 20, 6, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    cout << findInversions(A, 0, n - 1);
}