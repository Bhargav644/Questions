//* this is brute force with O(n*n) but we can do it wit O(nlogn) by priority queue to find minimum in queue

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vb vector<bool>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
int cost = 0;
vi key, parent;
vb mst;
int minInKey(int V)
{
    int mini = INT_MAX, minIndex;
    rep(i, 0, V)
    {
        if (mst[i] == false and key[i] < mini)
        {
            mini = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void primsAlgo(int V, vector<pair<int, int>> edges[])
{
    key = vi(V, INT_MAX);
    parent = vi(V, -1);
    mst = vb(V, false);

    key[0] = 0;
    parent[0] = -1;

    rep(count, 0, V - 1)
    {
        int u = minInKey(V);
        mst[u] = true;
        for (auto i : edges[u])
        {

            if (mst[i.first] == false and i.second < key[i.first])
            {
                key[i.first] = i.second;
                parent[i.first] = u;
            }
        }
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges[V];
    int w, x, y; // weight source and destination
    rep(i, 0, E)
    {
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }
    primsAlgo(V, edges);
    cout << "Edges Included in Spanning tree" << endl;
    for (int i = 1; i < V; i++) // becuaz 0 will consist of -1
        cout << parent[i] << " - " << i << " \n";
    cout << "Cost of Spanning tree: " << endl;
    for (int i = 1; i < V; i++) // becuaz 0 will consist of -1
        cost += key[i];
    cout << cost;
    return 0;
}