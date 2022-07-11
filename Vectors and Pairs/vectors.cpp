#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];//v1.push_back(value)
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector <int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;
    //swap(vector1,vector2)
    //v.pop_back()//deletes last element
    //vector <int> v2(3,50)//3 will be size and each element will be 50
    //sort(v.begin(),v.end())
    return 0;
}