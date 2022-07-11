//Test case: n=10  vector={1 0 1 1 1 1 0 1 1 1}    k=1
//at 7th position if we do change 0 to 1 it will maximum subarray of 1's
// 1 0 1 1 1 1 1 1 1 1  
//return length=8
#include <bits/stdc++.h>
using namespace std;
int find_subarray(vector<int> v,int k){
    int res=0,check_zero=0,j=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            check_zero++;
        }
        while(check_zero>k){
            if(v[j]==0){
                check_zero--;
            }
        j++;
        }
        res=max(res,i-j+1);
    }
    return res;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    cout<<find_subarray(v,k)<<endl;
    return 0;
}