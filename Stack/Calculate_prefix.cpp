#include <bits/stdc++.h>
#include<stack>
using namespace std;
int calculate_prefix(string s){
    int operand1,operand2;
    stack<int> st;
    for(int i=s.length();i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
            operand1=st.top();
            st.pop();
            operand2=st.top();
            st.pop();
            if(s[i]=='+'){
                st.push(operand1+operand2);
            }
            if(s[i]=='-'){
                st.push(operand1-operand2);
            }
            if(s[i]=='*'){
                st.push(operand1*operand2);
            }
            if(s[i]=='/'){
                st.push(operand1/operand2);
            }
        }
    }
    return st.top();
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    getline(cin,s);
    cin.ignore();
    cout<<calculate_prefix(s);
    return 0;
}