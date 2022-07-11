//aaaaabbbbbcccdddeee
//abcde
#include <bits/stdc++.h>
using namespace std;
string remove_duplicates(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string new_s=s.substr(1);
    if(ch==new_s[0]){
        return remove_duplicates(new_s);
    }
    return ch+remove_duplicates(new_s);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    cout<<remove_duplicates(s);
    return 0;
}