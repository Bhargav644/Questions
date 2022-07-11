#include <bits/stdc++.h>
using namespace std;

int maxE(int A[], int N)
{
    int maximum = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        maximum = max(maximum, A[i]);
    }
    return maximum;
}

int main()
{
    // your code goes here
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        int N, M;
        cin >> N >> M;
        int a[N], b[M];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> b[i];
        }
        int E = max(maxE(a, N), maxE(b, M));
        vector<int> v(E);

        for (int i = 0; i < N; i++)
        {
            v[a[i]] += 1;
        }
        int count = 0;
        for (int i = 0; i < M; i++)
        {
            v[b[i]] += 1;
            if (v[b[i]] == 2)
            {
                count += 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}
