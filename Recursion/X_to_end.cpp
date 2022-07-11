//axbxcx
//abcxxx
#include <bits/stdc++.h>
using namespace std;
string X_to_end(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string new_s=s.substr(1);
    if(ch=='x'){
        return X_to_end(new_s)+ch;
    }
    return ch+X_to_end(new_s);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    cout<<X_to_end(s);
    return 0;
}