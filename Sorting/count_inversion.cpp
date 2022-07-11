#include <bits/stdc++.h>
using namespace std;
long long merge(int *a,int start,int mid,int end){
    long long inv=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int a1[n1],a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[start+i];
    }
     for(int i=0;i<n2;i++){
        a2[i]=a[mid+1+i];
    }
    int i=0,j=0,k=start;
    while(i<n1 and j<n2){
        if(a1[i]<=a2[j]){
            a[k++]=a1[i++];
        }
        else{
            a[k++]=a2[j++];
            inv=n1-i;
        }
    }
    while(i<n1){
        a[k++]=a1[i++];
    }
    while(j<n2){
        a[k++]=a2[j++];
    }
    return inv;
}
long long count_inversion_through_divide(int *a,int start,int end){
    long long inv=0;
    if(start<end){
        int mid=(end+start)/2;
        inv+=count_inversion_through_divide(a,0,mid);
        inv+=count_inversion_through_divide(a,mid+1,end);
        inv+=merge(a,start,mid,end);
    }
    return inv;
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
    cout<<count_inversion_through_divide(a,0,n-1);
    return 0;
}