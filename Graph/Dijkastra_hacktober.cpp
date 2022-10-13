//! dijkastra works for both directed and undirected
//! it's a greedy algorithim
//! takes O(V*V) or O(V*E)
//! but by min heap it is O((V+E)logV)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define sp set<pair<int, int>>
#define vp vector<pair<int, int>>
#define inf 1e7
vi dijkstraAlgo(int V, int E, vp edges[], int source)
{
    vi dist(V, inf);
    dist[source] = 0;
    sp s; //{source,distance or weight}
    s.insert({0, source});
    while (!s.empty())
    {
        auto it = *(s.begin());
        s.erase(it);
        for (auto neighbour : edges[it.second])
        {
            if (dist[neighbour.first] > dist[it.second] + neighbour.second)
            {
                s.erase({dist[neighbour.first], neighbour.first});
                dist[neighbour.first] = dist[it.second] + neighbour.second;
                s.insert({dist[neighbour.first], neighbour.first});
            }
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
    vp edges[V];
    rep(i, 0, E)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }
    int source;
    cin >> source;
    vi distance = dijkstraAlgo(V, E, edges, source);
    cout << "Distance of each node from " << source << endl;
    rep(i, 0, V)
    {
        if (distance[i] != inf)
        {
            cout << i << "- >" << distance[i] << endl;
        }
    }
    cout << endl;
}