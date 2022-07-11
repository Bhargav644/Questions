#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    char x;
    cin>>x;

    try{
        if(isupper(x)){
            throw x;
        }
        if(!isalpha(x)){
            throw 23.5;
        }
        cout<<"Here Is Your Output "<<char(toupper(x));
    }
    catch(char x){
        cout<<"Enter a an alphabet in Lowercase";
    }
    catch(...){
        cout<<"Enter an Alphabet Please!!!";
    }
    return 0;
}