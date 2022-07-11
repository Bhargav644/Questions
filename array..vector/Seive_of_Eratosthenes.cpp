//find prime using unmarked and marked array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    int mark_unmark[100]={0};
    for(int i=2;i<=n;i++){
        if(mark_unmark[i]==0){
            for(int j=i*i;j<=n;j+=i){
                mark_unmark[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(mark_unmark[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}