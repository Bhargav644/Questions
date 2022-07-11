#include<bits/stdc++.h>
using namespace std;
void Insertion_Sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;// because of one extra j-- occurs
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // 0  1  2  3 4 
    // 12 13 5 40 2
    // 5 12 13 40 2
    // 1 3  5  4
}
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    Insertion_Sort(array,n);
    return 0;
}