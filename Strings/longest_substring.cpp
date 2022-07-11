#include <bits/stdc++.h>
#include <cstring>
using namespace std;
/*Easy method to find length*/
int long_substring_length_easy(string s){
    vector<int> dict(256,-1);
    int start=-1,maxLen=0;
    for(int i=0;i<s.length();i++){
        if(dict[s[i]]>start){
            start=dict[s[i]];
        }
        dict[s[i]]=i;
        maxLen=max(maxLen,i-start);
    }
    return maxLen;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin, s);
    cout << long_substring_length_easy(s)<<endl;
    return 0;
}