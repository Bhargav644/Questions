#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p,q;
    cin>>n>>m;
    cin>>p>>q;
    int a1[n][m];
    int a2[p][q];
    int result[n][q];

    for(int i=0;i<n;i++){
            for(int j=0;j<q;j++){
                result[i][j]=0;
            }
        }
    if(m!=p){
        cout<<"Number Of column of two matrix Should be same";
    }
    else{
        cout<<"Enter Your First Matrix"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a1[i][j];
            }
        }
        cout<<"Enter Your Second Matrix"<<endl;;
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                cin>>a2[i][j];
            }
        }
     //Multiplication starts here
     for(int i=0;i<n;i++){
         for(int j=0;j<p;j++){
             for(int k=0;k<m;k++){
                 result[i][j]+=a1[i][k]*a2[k][j];
             }
         }
     }
     cout<<"Your Multiplied Matrix Is"<<endl;
     for(int i=0;i<n;i++){
            for(int j=0;j<q;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}