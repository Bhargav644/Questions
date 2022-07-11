// greedy method first we will sort the edges list according to weight and then traverse them accordingly
// O(ElogV)
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vpi vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
vi childs;
int cost = 0;
class Disjoint
{
    vi parent;
    vi size;

public:
    Disjoint(int V)
    {
        parent = vi(V);
        size = vi(V);
        makeSet(V);
    }
    void makeSet(int V)
    {
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
};

void kruskalAlgo(int V, vii edges)
{
    Disjoint ds(V);
    for (auto e : edges)
    {
        int w = e[0];
        int x = e[1];
        int y = e[2];

        if (ds.findParent(x) == ds.findParent(y))
        {
            continue;
        }
        else
        {
            cost += w;
            cout << x << " " << y << " " << w << endl;
            ds.Union(x, y);
        }
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    vii edges;
    rep(i, 0, E)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
    }
    sort(edges.begin(), edges.end());
    cout << "Edges included in MST" << endl;
    kruskalAlgo(V, edges);
    cout << "Cost of MST :" << cost << endl;
    return 0;
}