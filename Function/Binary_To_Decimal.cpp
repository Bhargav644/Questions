#include<iostream>
#include<cmath>
using namespace std;
int BinaryToDecimal(int binary){
    int num=0;
    int i=0;
    int x=1;
    while(binary>0){
       int last=binary%10;
       num+=last*x;
       x*=2;
       i++;
       binary/=10;
    }
    return num;

}
int main(){
    int binary;
    cin>>binary;
    cout<<BinaryToDecimal(binary);
}