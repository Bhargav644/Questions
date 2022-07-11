#include<iostream>
using namespace std;
int find_factorial(int n){
    int fact=1;
   for(int i=2;i<=n;i++){
      fact*=i;
   }
   return fact;
}
int Calculate_NCR(int n,int r){
    int n_fact=find_factorial(n);
    int r_fact=find_factorial(r);
    int nr_fact=find_factorial(n-r);
    int ncr=n_fact/(r_fact*nr_fact);
    return ncr;
}
int main(){
    int n;
    cin>>n;
    cout<<"Your Pascal Triangle is"<<endl;;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<Calculate_NCR(i,j)<<' ';
        }
        cout<<endl;
    }
    return 0;
}







// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
