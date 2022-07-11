//a[0]>=a[1] <=a[2]>=a[3]<=a[4]>=a[5]=....
//time-complexity:n/2 becuz jump is of 2;
#include <bits/stdc++.h>
using namespace std;
void wave_sort(int *a,int n){
    for(int i=1;i<n;i+=2){
        if(a[i]>a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(a[i]>a[i+1] && i<=n-2){
            swap(a[i],a[i+1]);
        }
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
    wave_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}