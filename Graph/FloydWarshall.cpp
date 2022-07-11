//! can be done by greedy by dijkstra but floyd warshall is a dynamic algorithim
//! it's like adding an intermediate each time and checking path for it
//! complexity will O(n*n*n)
//? formula behind is SP^k[i,j]=min(SP^(k-1)[i,j],SP^(k-1)[i,k]+SP^(k-1)[k,j])
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vpi vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)

int inf = 1e8;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vii graph = {{0, 5, inf, 10}, {inf, 0, 3, inf}, {inf, inf, 0, 1}, {inf, inf, inf, 0}};
    vii adjM = graph;
    int V = adjM.size();
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                adjM[i][j] = min(adjM[i][j], adjM[i][k] + adjM[k][j]); // adding intermediate here
            }
        }
    }
    int source, destination;
    cin >> source >> destination;
    cout << adjM[source][destination] << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adjM[i][j] == inf)
            {
                cout << "INF ";
            }
            else
            {
                cout << adjM[i][j] << " ";
            }
        }
        cout << endl;
    }
}