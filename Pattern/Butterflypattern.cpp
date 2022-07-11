#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        for(int k=1;k<=n;k++){
            if(k<=n-i){
                cout<<' ';
            }
            else{
                cout<<'*';
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n+1-i){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        for(int k=1;k<=n;k++){
            if(k<i){
                cout<<' ';
            }
            else{
                cout<<'*';
            }
        }
        cout<<endl;
    }
    return 0;
}



// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *
