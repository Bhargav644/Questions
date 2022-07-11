#include <bits/stdc++.h>
using namespace std;
void all_substring(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code =ch;
    all_substring(s.substr(1),ans);
    all_substring(s.substr(1),ans+ch);
    all_substring(s.substr(1),ans+to_string(code));
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    all_substring(s,"");
    return 0;
}