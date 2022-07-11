#include <bits/stdc++.h>
#include<iostream>
using namespace std;
bool isMatch(string s,string p){
    string new_p="";
    if(p==".*"){
        return true;
    }
    else{
        for(int i=0;i<p.length();i++){
            if( i!=p.length()-1 &&p[i+1]=='*'){
                string str="";
                bool flag=false;
                int j=new_p.length();
                while(j<s.length()){
                    if(s[j]==p[i]){
                        flag=true;
                        str+=s[j];
                    }
                    else if(flag){
                        break;
                    }
                    j++;
                }
                new_p+=str;
            }
            else if(p[i]=='*'){
                continue;
            }
            else{
                new_p+=p[i];
            }
        }
        for(int i=0;i<new_p.length();i++){
            if(new_p[i]=='.'){
                new_p[i]=s[i];
            }
        }
    }
    cout<<new_p<<endl;
    return new_p==s;
  

}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    string str,exp;
    getline(cin,str);
    getline(cin,exp);
    cin.ignore();
    cout<<isMatch(str,exp)<<endl;

    return 0;
}
/*
aa
a
aa
a*
ab
.*
aab
c*a*b
mississippi
mis*is*p*.
*/