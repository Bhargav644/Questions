/*
O(nlogn)
ascending--max-heap
descending--min-heap
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
void heapSort(vi &given)
{
    for (int i = given.size() - 1; i > 0; i--)
    {
        swap(given[0], given[i]);
        max_heapify(given, i, 0);
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
    heapSort(given); // if we want this in descending just to min_heapify;
    rep(i, 0, size)
    {
        cout << given[i] << " ";
    }
    cout << endl;
}