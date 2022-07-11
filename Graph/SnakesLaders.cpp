/*
2 number of ladders
3 90   ---edges from where laader is
56 76  ---
3 number of snakes
99 10  ----edges from where snake is
30 20
20 5
Problem find the minimum step to reach 100
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define mpi map<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
int stepTo_100(mpi ladders, mpi snakes)
{
    bool visited[101] = {false};
    int moves = 0;
    queue<int> q;
    bool found = false;
    q.push(1);
    visited[1] = true;
    while (!q.empty() and !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            rep(die, 1, 7)
            {
                if (t + die == 100)
                {
                    found = true;
                }
                if (t + die <= 100 and ladders[t + die] and !visited[ladders[t + die]])
                {
                    visited[ladders[t + die]] = true;
                    if (ladders[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(ladders[t + die]);
                }
                else if (t + die <= 100 and snakes[t + die] and !visited[snakes[t + die]])
                {
                    visited[snakes[t + die]] = true;
                    if (snakes[t + die] == 100)
                    {
                        found = true;
                    }
                    q.push(snakes[t + die]);
                }
                else if (t + die <= 100 and !visited[t + die] and !snakes[t + die] and !ladders[t + die])
                {
                    visited[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if (found)
    {
        return moves;
    }
    return -1;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int L, S;
    cin >> L;
    mpi ladders;
    rep(i, 0, L)
    {
        int x, y;
        cin >> x >> y;
        ladders[x] = y;
    }
    cin >> S;
    mpi snakes;
    rep(i, 0, S)
    {
        int x, y;
        cin >> x >> y;
        snakes[x] = y;
    }
    cout << stepTo_100(ladders, snakes) << endl;
}