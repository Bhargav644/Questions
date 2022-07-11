/*
Heaps are complete Binary Trees(all levels are completely filed except possibly the
lowest one , which is filled from the left only)
we will represent them as an array where
childrens:2*i+1 and 2*i+2
parents:(i-1)//2
we have two types of heaps max heap(return max)/min heap(return min)
insertion-O(logV)
deletion-O(logV)
initernal nodes:0 to (n/2)-1
leaf nodes :n/2 to n-1
creating heap---------1.naive approach -heapify from 0 to n-1 -----O(nlogn)
             ---------2. optimal approach -heapify only internal nodes from last
             because leaf nodes are always heapified---O(n)
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector < vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, a, b) for (int i = a; i >= b; i--)
#define repe(i, a, b) for (int i = a; i <= b; i++)
void max_heapify(vi &given, int n, int i)
{
    int child1 = 2 * i + 1;
    int child2 = 2 * i + 2;
    int largest = i;
    if (child1 < n and given[child1] > given[largest])
    {
        largest = child1;
    }
    if (child2 < n and given[child2] > given[largest])
    {
        largest = child2;
    }
    if (largest != i)
    {
        swap(given[largest], given[i]);
        max_heapify(given, n, largest);
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vi given = {12, 11, 13, 5, 17, 7};
    int size = given.size();
    repn(i, (size / 2) - 1, 0)
    {
        max_heapify(given, size, i);
    }
    rep(i, 0, size)
    {
        cout << given[i] << " ";
    }
    cout << endl;
}