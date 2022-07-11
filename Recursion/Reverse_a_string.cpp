#include <bits/stdc++.h>
using namespace std;
void reverse_string(string s,int i,int n){
    if(i==n){
        return;
    }
    reverse_string(s,i+1,n);
    cout<<s[i];
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    reverse_string(s,0,s.length());
    cout<<endl;
    return 0;
}