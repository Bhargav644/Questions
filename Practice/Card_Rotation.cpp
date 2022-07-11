#include <bits/stdc++.h>
using namespace std;
vector<int> rotateVector(vector<int> vec2, int rt)
{
    int rotR = rt % vec2.size();
    rotate(vec2.begin(), vec2.begin() + vec2.size() - rotR, vec2.end());
    return vec2;
}
vector<int> rotation(int n)
{
    vector<int> vt;
    vt.push_back(n);
    n = n - 1;
    while (n > 0)
    {
        vt.insert(vt.begin(), n);
        vt = rotateVector(vt, n);
        n--;
    }
    return vt;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int a;
    cin >> a;
    vector<int> v = rotation(a);
    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
