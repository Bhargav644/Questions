#include <bits/stdc++.h>
using namespace std;
void pi_to_number(string s,int i){
    if(i==s.length()){
        cout<<s;
        return;
    }
    if(s.substr(i,2)=="pi"){
        s.erase(i,2);
        s.insert(i,"3.14");
    }
    return pi_to_number(s,i+1);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    pi_to_number(s,0);
    return 0;
}