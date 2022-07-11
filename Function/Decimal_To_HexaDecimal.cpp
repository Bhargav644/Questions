#include<bits/stdc++.h>
using namespace std;
string DecimalToHexa(int decimal){
    string s="";
    int divisor=1;
    while(divisor<=decimal){
        divisor*=16;
    }
    divisor/=16;
    while(divisor>0){
        int last=decimal/divisor;
        decimal=decimal-divisor*last;
        divisor/=16;
        if(last<=9){
            s=s+to_string(last);
        }
        else{
            char c ='A'+last-10;
            s.push_back(c);
        }
    }
    return s;
}
int main(){
    int decimal;
    cin>>decimal;
    cout<<DecimalToHexa(decimal);
    return 0;
}