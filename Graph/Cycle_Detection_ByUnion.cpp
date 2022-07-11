#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
vi parent(3);
vi size(3);
void makeSet(int V)
{
    parent = vi(V);
    size = vi(V);
    rep(i, 0, V)
    {
        parent[i] = i;
        size[i] = 0;
    }
}
int findParent(int child)
{
    if (parent[child] == child)
    {
        return child;
    }
    return parent[child] = findParent(parent[child]);
}
void Union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {

        if (size[u] < size[v])
        {
            swap(u, v);
        }
        else if (size[u] == size[v])
        {
            size[u] += 1;
        }
        parent[v] = u;
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, e;
    cin >> n >> e;
    makeSet(n);
    vector<pair<int, int>> edges(e);
    rep(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = (make_pair(x, y));
    }
    bool cycle = false;
    rep(i, 0, e)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        int x = findParent(u);
        int y = findParent(v);
        if (x == y)
        {
            cycle = true;
        }
        else
        {
            Union(u, v);
        }
    }
    cycle ? cout << "Detected" : cout << "Not Detected";
    return 0;
}