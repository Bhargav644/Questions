// by adjacency matrix it is O(nxn)
// by adjacency list it is  O(n+m)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
vb visited(100, 0); //! here remember size of visited should be maximum so that we can cover all elements
vi traversal;

void DFS(vi adjL[], int node)
{
    bool flag = false;
    if (!visited[node])
    {
        visited[node] = true;
        traversal.push_back(node);
    }
    vi::iterator it;
    for (it = adjL[node].begin(); it != adjL[node].end(); it++)
    {
        if (visited[*it] != 1)
        {
            DFS(adjL, *it);
            flag = true;
        }
    }
    if (!flag)
    {
        return;
    }
}

vi dfsOfGraphReccursive(int n, vi adjL[])
{

    DFS(adjL, 1); //? here 1 is starting point
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

    vi h = dfsOfGraphReccursive(n, adjL);
    rep(i, 0, h.size())
    {
        cout << h[i] << " -> ";
    }
    cout << endl;
    return 0;
}