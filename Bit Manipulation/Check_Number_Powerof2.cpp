#include<bits/stdc++.h>
using namespace std;
bool Power_Of_Two(int num){
    return (num && !(num&(num-1)));
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int num;
    cin>>num;
    if(Power_Of_Two(num)){
        cout<<"Number is Power of 2";
    }
    else{
        cout<<"Number is not a power of 2";
    }
    return 0;
}