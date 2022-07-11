#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n=4;
    int arr[4]={1,2,3,4};
    vector<int> v(n);
    stack<int> s;

    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
    int j=0;
    for(int i=n-1;i>=0;i--){
        if(s.top()<arr[i]){
            s.pop();
            v[j++]=-1;
        }
        else if(s.top()>arr[i]){
            v[j++]=s.top();
            s.pop();
        }
        else{
            v[j++]=-1;
        }
    }
    for(int i=n-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    return 0;
}