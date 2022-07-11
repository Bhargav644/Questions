/*Conditions for Bipartite Graph
1.We should be able to derive two disjoint sets U and V so that every element of U can connect with one element on V
2. Their should be no odd cycles
3. Graph should be 2 colourable (ex: for red colour vetices so their transparent vertices should be connected with blue coloured vertices)
vice versa for blue colour nodes
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define qp queue<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)
bool isBipartiteGraph(int V, vi adjL[])
{
    vi colour(V, -1);
    qp q;

    rep(i, 0, V)
    {
        if (colour[i] == -1)
        {
            q.push({i, 0});
            colour[i] = 0; // red
            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;

                for (auto j : adjL[v])
                {
                    if (colour[j] == c)
                    {
                        return false;
                    }
                    if (colour[j] == -1)
                    {
                        colour[j] = c xor 1;
                        q.push({j, colour[j]});
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, e;
    cin >> n >> e;
    vi adjL[n];
    vb visited(n);
    rep(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }

    isBipartiteGraph(n, adjL) ? cout << "Yes it is" : cout << "No";
}
