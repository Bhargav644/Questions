#include <bits/stdc++.h>
using namespace std;
string smallest(vector<string> strs){
        string s="";
        int j=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length()<j){
                j=strs[i].length();
                s=strs[i];
            }
        }
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string new_s="";
        int i=1;
        string small=smallest(strs);
        while(i<=strs[0].length()){
            string check=small.substr(0,i);
            bool flag=false;
            for(int j=0;j<strs.size();j++){
                if( check==strs[j].substr(0,i)){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                new_s=check;
            }
            i++;
        }
        if(strs.size()==1){
            return strs[0];
        }
        return new_s;
    }
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<string> strs(1);
    strs={"ab","a"};
    cout<<longestCommonPrefix(strs);
    return 0;
}