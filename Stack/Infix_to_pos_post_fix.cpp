//prefix has same algorithim as postfix but wwe have to reverse string if we
//want to convert it into prefix
#include <bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;
/*-----------------------------reverse a  string fro prefix exp-------------------------*/
string revers_string(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;

}
/*=======================change_brackets===================*/
void change_bracket(string &s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
}
/*=====================================================================*/
/*tells us the precendece of operator*/
int pre(char c){//precedance
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='-'||c=='+'){
        return 1;
    }
    else{
        return -1;
    }
}
/*---------------------------------------*/
//----------------can we used as pre and post algo-----------------------------//
string infix_to_pre_post(string s){
    stack <char> st;
    string ans;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            while((!st.empty()) && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if((s[i]>='A'&& s[i]<='Z') || (s[i]>='a'&& s[i]<='z')){
            ans+=s[i];
        }
        else{
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && pre(st.top())>pre(s[i])){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
/////////////////////-----------------------------------------////////
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string s;
    string str;
    getline(cin,s);
    if(s=="Prefix"){
        getline(cin,str);
        cin.ignore();
        change_bracket(str);
        cout<<revers_string(infix_to_pre_post(  revers_string(str)  ));
        //sending and receving reverse string
        //reverse(str.begin(),str.end());
        //well defined function by cpp for reversing
    }
    else{
         getline(cin,str);
         cin.ignore();
         cout<<infix_to_pre_post(str);
    }
    return 0;
}