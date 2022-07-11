#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, e;
    cin >> n >> e;
    vi adjL[n];

    rep(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
        adjL[y].push_back(x); //! only for undirected edges
    }
    rep(i, 0, n)
    {
        vector<int>::iterator it;
        cout << i << " -> ";
        for (it = adjL[i].begin(); it != adjL[i].end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
    return 0;
}
