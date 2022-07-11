// time complexity O(alpha(n)) inverse Ackermann function which is a ery small constant
// all union functions
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

vi parent(100);
vi size(100);

void make_set(int n)
{
    parent = vi(n);
    size = vi(n);
    rep(i, 0, n)
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
    if (size[u] < size[v])
    {
        swap(u, v);
    }
    else if (size[u] == size[v])
    {
        size[u]++;
    }
    parent[v] = u;
}
int main()
{
}