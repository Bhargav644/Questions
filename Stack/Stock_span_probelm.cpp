//INPUT:{100,80,60,70,64,75,85}
//OUTPPUT:{1,1,1,2,1,4,6};
//Consecutive lesser prices including the current one
#include <bits/stdc++.h>
using namespace std;
vector<int> stack_span(vector<int> v){
    vector<int> ans;
    stack<pair<int,int>> s;
    for(int i=0;i<v.size();i++){
        if(s.empty() || s.top().first>v[i]){
            s.push({v[i],1});
            ans.push_back(1);
        }
        else{
            int days=1;
            while(s.top().first<=v[i]){
                days+=s.top().second;
                s.pop();
            }
            s.push({v[i],days});
            ans.push_back(days);
        }
    }
    return ans;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v=stack_span(arr);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}