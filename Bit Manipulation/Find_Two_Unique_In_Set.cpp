#include <bits/stdc++.h>
using namespace std;
void Find_Two_Unique(int a[], int n)
{
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        Xor = Xor ^ a[i];
    }
    int first_Xor=Xor;
    int ourbit=0;
    int pos=0;
    while(ourbit!=1){
        ourbit=Xor&1;
        Xor=Xor>>1;
        pos++;
    }
    int new_Xor=0;
    for(int i=0;i<n;i++){
        if(a[i]&(1<<(pos-1))){
            new_Xor=new_Xor^a[i];
        }
    }
    cout<<new_Xor<<" "<<(new_Xor^first_Xor);
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
    Find_Two_Unique(arr, n);
    return 0;
}