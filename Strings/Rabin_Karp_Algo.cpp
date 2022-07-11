// O(mn)
// shifting of patt according to badHuristicSearch
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define d 256
const int MOD = 1e9 + 7;

void searchPat(string pat, string txt, int q)
{
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
            {
                t += q;
            }
        }
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEKS";
    int q = 101;
    searchPat(pat, txt, q);
    return 0;
}
