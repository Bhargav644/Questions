// O(mn)
// shifting of patt according to badHuristicSearch
// badHusistic search may take O(nm) time itself ex:AAAAAAA pat:AAAAA
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define NO_OF_CHAR 256
const int MOD = 1e9 + 7;
void badHeuristicSearch(string pat, int size, int badArray[])
{
    rep(i, 0, NO_OF_CHAR)
    {
        badArray[i] = -1;
    }
    rep(i, 0, size)
    {
        badArray[(int)pat[i]] = i;
    }
}
void searchPat(string pat, string txt)
{
    int n = txt.size();
    int m = pat.size();
    int badArray[NO_OF_CHAR];
    badHeuristicSearch(pat, m, badArray);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 and pat[j] == txt[s + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "Pattern at :" << s << endl;
            s += ((s + m) < n ? m - badArray[txt[s + m]] : 1);
        }
        else
        {
            s += max(1, j - badArray[txt[s + j]]);
        }
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string txt = "ABABCBABC";
    string pat = "ABC";
    searchPat(pat, txt);
    return 0;
}
