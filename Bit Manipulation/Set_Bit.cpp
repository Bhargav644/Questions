#include<bits/stdc++.h>
using namespace std;
int setbit(int n,int pos){//making the bit 1
    return ((n | (1<<pos)));
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cout<<setbit(5,1);
} 