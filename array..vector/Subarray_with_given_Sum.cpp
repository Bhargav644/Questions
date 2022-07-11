#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int Gsum;
    cin>>Gsum;
    int min_Index=0;
    int max_Index=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        int Osum=0;
        for(int j=i;j<n;j++){
            min_Index=i;
            Osum+=a[j];
            if(Osum==Gsum){
                max_Index=j;
                flag=true;
                break;
            }
            else{
                continue;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<min_Index+1<<" "<<max_Index+1;
    return 0;
}