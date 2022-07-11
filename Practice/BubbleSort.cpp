#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void BubbleSort(int arr[],int n){
    int swapped=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swapped=1;
            }
        }
        if(!swapped){
            break;
        }
    }
    printArray(arr,n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BubbleSort(arr,n);
    return 0;
}