#include<bits/stdc++.h>
using namespace std;
bool Check_Palindrome(char *a){
    int i=0;
    int size=0;
    while(a[i]!='\0'){
        i++;
        size++;
    }
    char b[size+1];
    for(int i=0;i<size;i++){
        b[i]=a[size-i-1];
    }
    if(strcmp(a,b)==0){
        return true;
    }
    return false;
}
int main(){
    char a[100];
    cin>>a;
    if(Check_Palindrome(a)){
        cout<<"Yes It Is a Palindrome";
    }
    else{
        cout<<"No It's Not A PAlindrome";
    }
    return 0;
}