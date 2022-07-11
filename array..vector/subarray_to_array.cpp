#include <bits/stdc++.h>
using namespace std;

#define vi vector<long>
#define rep(i, a, b) for (long i = a; i < b; i++)
bool Search(vi arr, long l, long r, long x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return true;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    long tcase;
    cin >> tcase;
    while (tcase--)
    {
        long n, j = 0;
        cin >> n;
        long sizeS = long(pow(2, n));
        vi v(sizeS), ans(n);
        rep(i, 0, sizeS)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        v.erase(v.begin());
        ans[j++] = v[1];
        long currSum = v[1], mainSum = v[sizeS - 1];
        rep(i, 2, sizeS)
        {
            if (j == n)
            {
                break;
            }
            else if (j == n - 1)
            {
                ans[j++] = mainSum - currSum;
                break;
            }
            else
            {
                long checkSum = currSum + v[i];
                if (Search(v, 0, sizeS, checkSum))
                {
                    ans[j++] = v[i];
                    currSum += v[i];
                }
            }
        }

        rep(i, 0, n)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
