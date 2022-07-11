#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;
void print(vi list)
{
    for (int i : list)
    {
        cout << i << " ";
    }
    cout << endl;
}
void subSequence(int index, vi list, int *arr, int n)
{
    // cout << index << endl;
    if (index >= n)
    {
        print(list);
        return;
    }
    cout << "Index in:" << index << endl;
    list.push_back(arr[index]);
    subSequence(index + 1, list, arr, n);
    cout << "Index mid:" << index << endl;
    list.pop_back();
    subSequence(index + 1, list, arr, n);
    cout << "Index out:" << index << endl;
    return;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int arr[3] = {3, 1, 2};
    subSequence(0, {}, arr, 3);
    return 0;
}