#include<bits/stdc++.h>
using namespace std;
int clearbit(int n,int pos){//means making 0
    return ((n & (~(1<<pos))));
}
int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    cout<<clearbit(5,0);
} 