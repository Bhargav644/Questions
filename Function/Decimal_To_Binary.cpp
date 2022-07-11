#include<bits/stdc++.h>
using namespace std;
int DecimalToBinary(int decimal){
    int divisor=1;
    int num=0;
    while(divisor<=decimal){
        divisor*=2;
    }
    divisor/=2;
    while(decimal>0){
        int last=decimal/divisor;
        decimal-=last*divisor;
        divisor/=2;
        num=num*10+last;
    }
    return num;
}
int main() {
    int decimal;
    cin>>decimal;
    cout<<DecimalToBinary(decimal);
    return 0;
}
