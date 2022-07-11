#include<iostream>
using namespace std;
int find_factorial(int n){
    int fact=1;
   for(int i=2;i<=n;i++){
      fact*=i;
   }
   return fact;
}
int main(){
    int n,r;
    cin>>n>>r;
    int n_fact=find_factorial(n);
    int r_fact=find_factorial(r);
    int nr_fact=find_factorial(n-r);
    int ncr=n_fact/(r_fact*nr_fact);
    cout<<"The C(N,R) is: "<<ncr;
    return 0;
}