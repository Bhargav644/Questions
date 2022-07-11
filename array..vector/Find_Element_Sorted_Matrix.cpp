#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int target;cin>>target;
    bool flag=false;
    int r=0,c=n-1;
    while(r<=n-1 && c>=0){
        if(a[r][c]==target){
            flag=true;
            break;
        }
        if(a[r][c]<target){
            r++;
        }
        else{
            c--;
        }
    }
    if(flag){
        cout<<"Element Found";
    }
    else{
        cout<<"Element Not Find";
    }
    return 0;
}