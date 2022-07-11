//time complexity O(n+maximum_element)
#include <bits/stdc++.h>
using namespace std;
void count_sort(int *a,int n){
    int maximum=a[0];
    for(int i=0;i<n;i++){
        maximum=max(maximum,a[i]);
    }
    int count[maximum]={0};
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=maximum;i++){
        count[i]=count[i]+count[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=ans[i];
    }
}
void print_array(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    count_sort(a,n);
    print_array(a,n);
    return 0;
}