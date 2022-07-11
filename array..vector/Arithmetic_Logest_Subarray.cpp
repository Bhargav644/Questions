// arthmetic array:array aur subarray ao that differens=ce between consecutive elements is equal 
//ex:{9,4},{3,3,3}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int pd=array[1]-array[0];//previous difference
    int j=2;
    int answer=2;
    int current=2;
    while(j<n){
        if(pd==array[j]-array[j-1]){
            current++;
        }
        else{
            pd=array[j]-array[j-1];
            current=2;
        }
        answer=max(answer,current);
        j++;
    }
    cout<<answer;

}