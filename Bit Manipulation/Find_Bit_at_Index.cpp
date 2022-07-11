#include<bits/stdc++.h>
using namespace std;
int getbit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cout<<getbit(5,1);
} 