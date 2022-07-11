#include <bits/stdc++.h>
#include<stack>
using namespace std;
bool is_valid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' or s[i]=='[' or s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }


    }
    return st.empty();
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    if(is_valid(s)){
        cout<<"VALID";
    }
    else{
        cout<<"INVALID";
    }
    return 0;
}