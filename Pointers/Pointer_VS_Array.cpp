#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<arr<<endl;//constant pointer points to first element of array
    cout<<*arr<<endl;
    int *ptr=arr;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<"By PTR Pointer"<<endl;  
    for(int i=0;i<5;i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl<<"By ARRAY Pointer"<<endl;   
    for(int i=0;i<5;i++){
        cout<<*(arr+i)<<" ";
    }   
    return 0;
}