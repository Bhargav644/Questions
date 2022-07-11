// works basically on basis of pivot
// time-complexity:nlogn//..bestcase//..pivot will be median
// time-complexity:O(n^2)//..pivot will be starting point or end point
#include <bits/stdc++.h>
using namespace std;
int arrange_about_pivot(int *a, int start, int end)
{ // returns index of pivot
    int assumed_pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < assumed_pivot)
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
}
void divide_and_conqour(int *a, int start, int end)
{ // divide the array about to pivot
    if (start < end)
    {
        int pivot = arrange_about_pivot(a, start, end);
        divide_and_conqour(a, start, pivot - 1);
        divide_and_conqour(a, pivot + 1, end);
    }
}
void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)

    {
        cout << a[i] << " ";
    }
    cout << endl;
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
    divide_and_conqour(a, 0, n - 1);
    print_array(a, n);
    return 0;
}