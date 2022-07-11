//ex n=6
//arr={1,2,5,3,5,3}
//output will be index 2 or 3 (if  indexing starts from 1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    const int N=1e3+2;
    int index[N];
    for(int i=0;i<N;i++){
        index[i]=-1;
    }
    int min_Index=INT_MAX;
    for(int i=0;i<n;i++){
        if(index[array[i]]!=-1){
            min_Index=min(min_Index,index[array[i]]);
        }
        else{
            index[array[i]]=i;
        }
    }
    if(min_Index==INT_MAX){
        cout<<"-1";
    }
    else{
        cout<<min_Index+1<<endl;
    }
    return 0;
}
//ind[]={-1,-1,-1,-,1-,1-,1}
//arr[]={1,2,5,3,3,5}