#include <bits/stdc++.h>
using namespace std;
int roman_to_int(string s){
    vector <pair<char,int>> alpha(7);
    /*=====================declaring roman charactetrs============*/
    alpha[0].first='I'; alpha[0].second=1;
    alpha[1].first='V'; alpha[1].second=5;
    alpha[2].first='X'; alpha[2].second=10;
    alpha[3].first='L'; alpha[3].second=50;
    alpha[4].first='C'; alpha[4].second=100;
    alpha[5].first='D'; alpha[5].second=500;
    alpha[6].first='M'; alpha[6].second=1000;
    /*============================================================*/
    int value=0;
    int i=0;
    stack<int> st;
    while(i<s.length()){
        for(int j=0;j<7;j++){
            if(s[i]==alpha[j].first){
                st.push(alpha[j].second);
                break;
            }
            else{
                continue;
            }
        }
        i++;
    }
    while(!st.empty()){
        int k=st.top();
        st.pop();
        if(st.top()<k && !st.empty()){
            value+=k-st.top();
            st.pop();
        }
        else{
            value+=k;

        }
    }
    return value;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cout<<roman_to_int(s)<<endl;
    return 0;
}
/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/