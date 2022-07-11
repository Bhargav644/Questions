//*detecting cycle using dfs fro undirected graph
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
bool isCycle(int node, vector<int> adjL[], vector<bool> &visited, int parent)
{
    visited[node] = true;
    for (auto it : adjL[node])
    {
        if (visited[it] == 0)
        {
            if (isCycle(it, adjL, visited, node))
                return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}
bool DetectCycle(int n, vi adjL[])
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and isCycle(i, adjL, visited, -1))
        {
            return true;
        }
    }
    return false;
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
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    if (DetectCycle(n, adjL))
    {
        cout << "Cycle Detetcted" << endl;
    }
    else
    {
        cout << "Cycle not Detected" << endl;
    }
    return 0;
}