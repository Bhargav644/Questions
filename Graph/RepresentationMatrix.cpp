#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, e; // nondes,edges
    cin >> n >> e;
    vii adjM(n + 1, vi(n + 1, 0));
    rep(i, 0, e)
    {
        int x, y;
        cin >> x >> y;
        adjM[x][y] = 1;
        adjM[y][x] = 1;
    }
    rep(i, 0, n + 1)
    {
        adjM[0][i] = i; /// for sake o findexex nothing else
        adjM[i][0] = i;
    }
    rep(i, 0, n + 1)
    {
        rep(j, 0, n + 1)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }
}
