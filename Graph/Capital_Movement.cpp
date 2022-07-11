#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second > b.second);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int tcase;
    vi::iterator it;
    cin >> tcase;
    while (tcase--)
    {
        int n;
        cin >> n;
        vi population(n);
        rep(i, 0, n)
        {
            cin >> population[i];
        }
        vector<pair<int, int>> maxer(n);
        rep(i, 0, n)
        {
            maxer[i] = make_pair(i + 1, population[i]);
        }
        sort(maxer.begin(), maxer.end(), sortbysec);

        vi adjL[n + 1];
        rep(i, 0, n - 1)
        {
            int x, y;
            cin >> x >> y;
            adjL[x].push_back(y);
            adjL[y].push_back(x);
        }
        vector<bool> visited(n + 1, false);
        rep(i, 1, n + 1)
        {
            for (it = adjL[i].begin(); it != adjL[i].end(); it++)
            {
                visited[*it] = true;
            }
            int max_index = 0;
            rep(j, 0, n)
            {
                if (maxer[j].first != i and visited[maxer[j].first] != true)
                {
                    max_index = maxer[j].first;
                    break;
                }
            }
            cout << max_index << " ";
            for (it = adjL[i].begin(); it != adjL[i].end(); it++)
            {
                visited[*it] = false;
            }
        }
        cout << endl;
    }
    return 0;
}