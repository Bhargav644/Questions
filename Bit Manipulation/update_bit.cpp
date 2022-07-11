#include<bits/stdc++.h>
using namespace std;
int updatebit(int n,int pos,int value){
    int mask=~(1<<pos);
    n=n&mask;
    return ((n | (value<<pos)));
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cout<<updatebit(5,1,1);
} 