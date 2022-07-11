//! same for shortest path
#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define iterate vi::iterator
#define rep(i, a, b) for (int i = a; i < b; i++)

int longestPath_inDAG(int n, vi adjL[])
{
    vi indegree(n, 0), height(n, 0);
    iterate it;
    queue<int> q;
    int lPath = 0;
    for (int i = 0; i < n; i++)
    {
        for (it = adjL[i].begin(); it != adjL[i].end(); it++)
        {
            indegree[*it] += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        indegree[top] -= 1;
        q.pop();
        for (it = adjL[top].begin(); it != adjL[top].end(); it++)
        {
            indegree[*it] -= 1;
            height[*it] = max(height[top] + 1, height[*it]);
            if (indegree[*it] == 0)
            {
                q.push(*it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        lPath = max(lPath, height[i]);
    }
    return lPath;
}
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
        adjL[x].push_back(y); //? directed that's why
    }
    cout << longestPath_inDAG(n, adjL);
    return 0;
}