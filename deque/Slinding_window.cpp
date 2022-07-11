#include <bits/stdc++.h>
#include<deque>
using namespace std;
vector<int> find_max_list(vector<int> a,int k){
    vector<int> ans;
    //for our maximum answers
    deque<int> q;
    //becuz of this deque we are able to insert delete from both end
    int i;
    for(i=0;i<k;i++){
        while((!q.empty()) && a[i]>a[q.back()] ){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    
    for(;i<a.size();i++){
        if(q.front()==i-k){
            q.pop_back();
        }
        while((!q.empty()) && a[i]>a[q.back()] ){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    return ans;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int c,window_size;
    cin>>c>>window_size;
    vector<int> a(c);
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    vector<int> ans(c-window_size+1);
    ans=find_max_list(a,window_size);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}