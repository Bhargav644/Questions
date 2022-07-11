//! bellman Ford works for both directed and undirected and also for negative edges
//! it can also find negative cycles because of negative cycles/total weight
//! upsation of distance array is relaxation
//! O(VE)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define sp set<pair<int, int>>
#define vp vector<pair<int, int>>
#define inf 1e7

vi bellmanFordAlgo(int V, int E, vii edges, int source)
{
    vi dist(V, inf);
    dist[source] = 0;
    rep(i, 0, V - 1)
    {
        for (auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            int w = edge[2];
            dist[y] = min(dist[y], dist[x] + w);
            // dist[x] = min(dist[x], dist[y] + w);
        }
    }
    return dist;
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
        edges.push_back({x, y, w});
    }
    int source;
    cin >> source;
    vi distance = bellmanFordAlgo(V, E, edges, source);
    cout << "Distance of each node from " << source << endl;
    rep(i, 0, V)
    {
        if (distance[i] != inf)
        {
            cout << i << " -> " << distance[i] << endl;
        }
    }
    cout << endl;
}