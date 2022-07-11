#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class maxMin
{
public:
    int min = INT_MAX, max = INT_MIN;
};
maxMin obj;
maxMin maxiMini(int *arr, int start, int end)
{
    if (start == end)
    {
        maxMin here;
        here.min = arr[start];
        here.max = arr[end];
        return here;
    }
    if (start < end)
    {
        int mid = (start + end) / 2;
        maxMin a = maxiMini(arr, start, mid);
        maxMin b = maxiMini(arr, mid + 1, end);

        obj.min = min(a.min, b.min);
        obj.max = max(a.max, b.max);
    }
    return obj;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    maxMin obj = maxiMini(arr, 0, n - 1);
    cout << obj.min << " " << obj.max;
}