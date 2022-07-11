#include <bits/stdc++.h>
using namespace std;
int Total_bits(int a){
    int count=0;//count of set bits(1)
    while(a!=0){
        int ourbit=a&1;
        if(ourbit==1){
            count++;
        }
        a=a>>1;
    }
    return count;
}
int Find_unique(int a[], int n)
{
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        Xor = Xor ^ a[i];
    }
    int our;
    for(int i=0;i<n;i++){
        if(Total_bits(a[i]&(~Xor))==1){
            our=a[i];
            break;
        }
    }
    return our;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Find_unique(arr, n);
    return 0;
}