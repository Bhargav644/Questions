// by adjacency matrix it is O(nxn)
// by adjacency list it is  O(n+m)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
vi bfsOfGraph(int n, vi adjL[])
{
    queue<int> q;
    vi traversal;
    vb visited(n, 0); //! here remember size of visited should be maximum so that we can cover all elements
    q.push(7);
    visited[7] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        traversal.push_back(top);
        vi::iterator it;
        for (it = adjL[top].begin(); it != adjL[top].end(); it++)
        {
            if (visited[*it] != 1)
            {
                q.push(*it);
                visited[*it] = 1;
            }
        }
    }
    return traversal;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, e;
    cin >> n >> e;
    vi adjL[n + 1]; //! here remember size of visited should be maximum so that we can cover all elements

    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    vi h = bfsOfGraph(5, adjL);
    rep(i, 0, h.size())
    {
        cout << h[i] << " -> ";
    }
    cout << endl;
    return 0;
}