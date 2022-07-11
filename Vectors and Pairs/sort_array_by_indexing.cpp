// 6 7 1 3 2
//output : 3 4 0 2 1(indexes)
#include <bits/stdc++.h>
#include<vector>
using namespace std;
bool compare(pair<int,int> p1,pair <int,int> p2){
    return p1.first<p2.first;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int v[5]={6,7,1,3,2};
    vector <pair<int,int>> vec;
    for(int i=0;i<5;i++){
        // pair<int,int> p;
        // p.first=v[i];
        // p.second=i;
        // vec.push_back(p);
        vec.push_back(make_pair(v[i],i));
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<5;i++){
        v[vec[i].second]=i;
    }
    for(int i=0;i<vec.size();i++){
        cout<<v[i];
    }
    cout<<endl;
    return 0;
}