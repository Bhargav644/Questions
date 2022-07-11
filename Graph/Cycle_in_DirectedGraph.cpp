//*detecting cycle using dfs for directed graph
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
bool isCycleCheck(int node, vector<bool> visited, vector<bool> &currVisit, vi adjL[])
{
    visited[node] = true;
    currVisit[node] = true;
    for (auto it : adjL[node])
    {
        if (!visited[it])
        {
            if (isCycleCheck(it, visited, currVisit, adjL))
                return true;
        }
        else if (currVisit[node])
        {
            return true;
        }
    }
    currVisit[node] = false;
    return false;
}
bool DetectCycle(int n, vi adjL[])
{
    vector<bool> visited(n, false), currVisit(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCycleCheck(i, visited, currVisit, adjL))
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
        adjL[x].push_back(y); //! only directed
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