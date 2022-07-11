#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        int Ig[M], Tr[K];
        vector<int> arr(N + 1, 0);
        for (int i = 0; i < M; i++)
        {
            cin >> Ig[i];
        }
        for (int i = 0; i < K; i++)
        {
            cin >> Tr[i];
        }
        for (int i = 0; i < M; i++)
        {
            arr[Ig[i]] += 1;
        }
        for (int i = 0; i < K; i++)
        {
            arr[Tr[i]] += 1;
        }
        int countTI = 0, countUU = 0;
        for (int i = 1; i <= N; i++)
        {
            if (arr[i] == 2)
            {
                countTI += 1;
            }
            else if (arr[i] == 0)
            {
                countUU += 1;
            }
        }
        cout << countTI << " " << countUU << endl;
    }

    return 0;
}
