#include<iostream>
using namespace std;
void moveleft(int array[],int d,int n){
    for(int i=0;i<d;i++){
        int temp=array[0];
        for(int j=0;j<n-1;j++){
           array[j]=array[j+1];
        }
        array[n-1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
        
    }
}
int main(){
   int n,d;
   cout<<"Enter the size of array";
   cin>>n;
   int a[n];
   cout<<"Enter your elements";
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   cout<<"Enter upto which index you want to move the array";
   cin>>d;
   moveleft(a,d,n);
}