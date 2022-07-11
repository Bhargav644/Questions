// A days whose previous day has less value and greater than following days

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    a[n]=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    int j=0;
    int maximum=-1;
    int rbdays=0;//record breaking days
    while(j<n){
        if(a[j]>maximum && a[j]>a[j+1]){
            rbdays++;
        }
        maximum=max(maximum,a[j]);
        j++;
    }
    cout<<rbdays;
    return 0;
}
