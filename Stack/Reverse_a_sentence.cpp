#include <bits/stdc++.h>
#include<stack>
using namespace std;
void reverse_string(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!s.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    reverse_string(s);
    return 0;
}