#include<iostream>
using namespace std;
int gcd(int,int);
int main(){
    int first,second;
    cin>>first>>second;
    int GCD=gcd(first,second);
    cout<<GCD;
}
int gcd(int i,int j){
    int k=2;
    int product=1;
    if(i==1 || j==1)
       return 1;
    else{
        while(i>1 && j>1){
             if(i%k==0){
                 if(j%k==0){
                     product=product*k;
                     j=j/k;
                     i=i/k;
                 }
                 else{
                     i=i/k;
                     k++;
                     continue;
                 }
             }
             else{
                 k++;
                 continue;
             }
        }
        return product;
    } 
}