#include<bits/stdc++.h>
using namespace std;
int Hexa_To_Decimal(string hexa){
    int size=hexa.size();
    int x=1;
    int num=0;
    for(int i=size-1;i>=0;i--){
        if(hexa[i] >= '0' && hexa[i] <= '9'){
             num+=x*(hexa[i]-'0');
        }
        else if(hexa[i] >= 'A' && hexa[i] <= 'F'){              //A=10,B=11.......F=15;
             num+=x*((hexa[i]-'A')+10);
        }
        x*=16;
    }
    return num;
}
int main(){
    string hexa;
    cin>>hexa;
    cout<<"Your Decimal Value is:"<<endl;
    cout<<Hexa_To_Decimal(hexa);
}