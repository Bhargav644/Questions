#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int min_Positive;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int N=1e4+2;
    bool checked[N];
    for(int i=0;i<N;i++){
        checked[i]=false;
    }
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            checked[a[i]]=true;
        }
    }
    for(int i=0;i<N;i++){
        if(checked[i]==false){
            min_Positive=i;
            break;
        }
    }
    cout<<min_Positive<<endl;
    return 0;
}