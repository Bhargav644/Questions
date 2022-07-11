//time-complexity:nlogn;//for all case
//expression:T(n/2)+T(n/2)+n=2T(n/2)+n
#include <bits/stdc++.h>
using namespace std;
void merge_array(int *a,int s,int mid,int e){
    int size1=(mid-s+1);
    int size2=(e-mid);
    int array1[size1],array2[size2];
    for(int i=0;i<size1;i++){
        array1[i]=a[s+i];
    }
    for(int i=0;i<size2;i++){
        array2[i]=a[mid+1+i];
    }
    int i=0,j=0,k=s;
    while(i<size1 && j<size2){
        if(array1[i]<array2[j]){
            a[k]=array1[i];
            k++;
            i++;
        }
        else{
            a[k]=array2[j];
            k++;
            j++;
        }
    }
    while(i<size1){
        a[k]=array1[i];
            k++;
            i++;
    }
    while(j<size2){
        a[k]=array2[j];
            k++;
            j++;
    }

}
void divide_and_conquer(int *a,int s,int e){
    if(s<e){
        int mid=(e+s)/2;
        divide_and_conquer(a,s,mid);
        divide_and_conquer(a,mid+1,e);
        merge_array(a,s,mid,e);
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    divide_and_conquer(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}