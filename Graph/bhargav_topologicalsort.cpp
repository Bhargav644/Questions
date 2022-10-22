// by adjacency matrix it is O(nxn)
// by adjacency list it is  O(n+m)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
vi topologicalSort(int n, vi adjL[])
{
    vi::iterator it;
    vi indegree(n, 0), traversal;
    for (int i = 0; i < n; i++)
    {
        for (it = adjL[i].begin(); it != adjL[i].end(); it++)
        {
            indegree[*it] += 1;
        }
    }

    queue<int> zeroDegree;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            zeroDegree.push(i);
        }
    }
    while (!zeroDegree.empty())
    {
        int top = zeroDegree.front();
        zeroDegree.pop();
        traversal.push_back(top);
        // indegree[top] -= 1; //! not neccessary just for sake of info
        for (it = adjL[top].begin(); it != adjL[top].end(); it++)
        {
            indegree[*it] -= 1;
            if (indegree[*it] == 0)
            {
                zeroDegree.push(*it);
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
    vi adjL[n]; //! here remember size of visited should be maximum so that we can cover all elements

    rep(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
    }

    vi h = topologicalSort(n, adjL);
    rep(i, 0, n)
    {
        cout << h[i] << " -> ";
    }
    cout << endl;
    return 0;
}